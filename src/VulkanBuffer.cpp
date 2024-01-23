#include "VulkanBuffer.h"

#include <cstring>

namespace vkcpp{
VulkanBuffer::~VulkanBuffer()
{
    VkDevice device = vkcppDevice.getLogicalDevice();
    vkDestroyBuffer(device, buffer, nullptr);
    vkFreeMemory(device, bufferMemory, nullptr);
}

void VulkanBuffer::create(void* hostData, VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties){
    VkDevice device = vkcppDevice.getLogicalDevice();
    createBuffer(size, usage, properties, buffer, bufferMemory);
    void* data;
    vkMapMemory(device, bufferMemory, 0, size, 0, &data);
        memcpy(data, hostData, static_cast<size_t>(size));
    vkUnmapMemory(device, bufferMemory);
}


// void VulkanBuffer::destroy(){
//     VkDevice device = vkcppDevice.getLogicalDevice();
//     vkDestroyBuffer(device, buffer, nullptr);
//     vkFreeMemory(device, bufferMemory, nullptr);
// }


void VulkanBuffer::createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory) {
    VkDevice device = vkcppDevice.getLogicalDevice();
    VkPhysicalDevice physicalDevice = vkcppDevice.getPhysicalDevice();
    VkBufferCreateInfo bufferInfo{};
    bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bufferInfo.size = size;
    bufferInfo.usage = usage;
    bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

    if (vkCreateBuffer(device, &bufferInfo, nullptr, &buffer) != VK_SUCCESS) {
        throw std::runtime_error("failed to create buffer!");
    }

    VkMemoryRequirements memRequirements;
    vkGetBufferMemoryRequirements(device, buffer, &memRequirements);

    VkMemoryAllocateInfo allocInfo{};
    allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocInfo.allocationSize = memRequirements.size;
    allocInfo.memoryTypeIndex = findMemoryType(physicalDevice, memRequirements.memoryTypeBits, properties);

    if (vkAllocateMemory(device, &allocInfo, nullptr, &bufferMemory) != VK_SUCCESS) {
        throw std::runtime_error("failed to allocate buffer memory!");
    }

    vkBindBufferMemory(device, buffer, bufferMemory, 0);
    bufferSize = size;
}

void VulkanBuffer::copyBufferTo(VulkanCommandManager& vkcppCmdManager, VkBuffer dstBuffer, VkDeviceSize size) {
    VkCommandBuffer commandBuffer = vkcppCmdManager.beginSingleTimeCommands();

    VkBufferCopy copyRegion{};
    copyRegion.size = size;
    vkCmdCopyBuffer(commandBuffer, buffer, dstBuffer, 1, &copyRegion);

    vkcppCmdManager.endSingleTimeCommands(commandBuffer);
}



}