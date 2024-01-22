#ifndef VULKANBUFFER_H
#define VULKANBUFFER_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "VulkanDevice.h"
#include "VulkanCommand.h"

namespace vkcpp{

class VulkanBuffer{
public:
    VulkanBuffer(VulkanDevice& vkcppDevice) : vkcppDevice(vkcppDevice){};
    ~VulkanBuffer();
    VulkanBuffer(const VulkanBuffer& other) = delete;
    VulkanBuffer& operator=(const VulkanBuffer& other) = delete;
    void create(
        void *hostData, 
        VkDeviceSize size, 
        VkBufferUsageFlags usage, 
        VkMemoryPropertyFlags properties
    );

    void destroy();
    VkBuffer getBuffer(){return buffer;}
    void copyBufferTo(
        VulkanCommandManager& vkcppCmdManager,  
        VkBuffer dstBuffer, 
        VkDeviceSize size
    );


private:
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

}
;
}

#endif