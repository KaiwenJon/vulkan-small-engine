#ifndef VULKANBUFFER_H
#define VULKANBUFFER_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "VulkanDevice.h"

namespace vkcpp{

class VulkanBuffer{
public:
    VulkanBuffer(VulkanDevice& vkcppDevice) : vkcppDevice(vkcppDevice){};
    ~VulkanBuffer();
    VulkanBuffer(const VulkanBuffer& other) = delete;
    VulkanBuffer& operator=(const VulkanBuffer& other) = delete;
private:
    void createBuffer(
        VkDeviceSize size, 
        VkBufferUsageFlags usage, 
        VkMemoryPropertyFlags properties, 
        VkBuffer& buffer, 
        VkDeviceMemory& bufferMemory
    );

    VulkanDevice& vkcppDevice;

}
;
}

#endif