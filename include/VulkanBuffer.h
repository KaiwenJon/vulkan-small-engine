#ifndef VULKANBUFFER_H
#define VULKANBUFFER_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


#include "VulkanCommand.h"

namespace vkcpp{
class VulkanDevice;
class VulkanCommandManager;
class VulkanBuffer{
public:
    VulkanBuffer(VulkanDevice& vkcppDevice) : vkcppDevice(vkcppDevice){};
    ~VulkanBuffer();
    VulkanBuffer(const VulkanBuffer& other) = delete;
    VulkanBuffer& operator=(const VulkanBuffer& other) = delete;
    VulkanBuffer(VulkanBuffer&& other) : vkcppDevice(other.vkcppDevice){
        buffer = other.buffer;
        bufferMemory = other.bufferMemory;
        bufferSize = other.bufferSize;
        other.buffer = VK_NULL_HANDLE;
        other.bufferMemory = VK_NULL_HANDLE;
        other.bufferSize = 0;
    }
    void create(
        void *hostData, 
        VkDeviceSize size, 
        VkBufferUsageFlags usage, 
        VkMemoryPropertyFlags properties
    );

    // void destroy();
    VkBuffer getBuffer(){return buffer;}
    void copyBufferTo(
        VulkanCommandManager& vkcppCmdManager,  
        VkBuffer dstBuffer, 
        VkDeviceSize size
    );


protected:
    void createBuffer(
        VkDeviceSize size, 
        VkBufferUsageFlags usage, 
        VkMemoryPropertyFlags properties, 
        VkBuffer& buffer, 
        VkDeviceMemory& bufferMemory
    );

    VulkanDevice& vkcppDevice;
    VkBuffer buffer;
    VkDeviceMemory bufferMemory;
    VkDeviceSize bufferSize=0;
}
;
}

#endif