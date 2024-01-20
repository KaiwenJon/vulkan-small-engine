#ifndef VULKANDEVICE_H
#define VULKANDEVICE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "VulkanDebugger.h"

namespace vkcpp{

class VulkanDevice{
public:
    VulkanDevice();
    ~VulkanDevice();
    VulkanDevice(const VulkanDevice& other) = delete;
    VulkanDevice& operator=(const VulkanDevice& other) = delete;
    void setup(VkInstance instance, VkSurfaceKHR surface, VulkanDebugger& vkcppDebugger);

    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;
    VkQueue graphicsQueue;
    VkQueue presentQueue;
private:
    void pickPhysicalDevice(VkInstance instance, VkSurfaceKHR surface);
    void createLogicalDevice(VkSurfaceKHR surface, VulkanDebugger& vkcppDebugger);
    const std::vector<const char*> deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
    };
};


}


#endif