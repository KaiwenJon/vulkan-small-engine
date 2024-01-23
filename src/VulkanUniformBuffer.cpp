#include "VulkanUniformBuffer.h"

namespace vkcpp{
VulkanUniformBuffer::~VulkanUniformBuffer()
{
}

void VulkanUniformBuffer::createUniformBuffer(VkDeviceSize size){
    createBuffer(
        size, 
        VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, 
        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, 
        buffer, 
        bufferMemory
    );

    vkMapMemory(
        vkcppDevice.getLogicalDevice(), 
        bufferMemory, 
        0, 
        size, 
        0, 
        &uniformBufferMapped
    );

}



}