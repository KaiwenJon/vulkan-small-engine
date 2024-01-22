#ifndef VULKANDEVICE_H
#define VULKANDEVICE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "VulkanDebugger.h"
#include "utils.h"

namespace vkcpp{

class VulkanDevice{
public:
    VulkanDevice();
    ~VulkanDevice();
    VulkanDevice(const VulkanDevice& other) = delete;
    VulkanDevice& operator=(const VulkanDevice& other) = delete;
    void setup(VkInstance instance, VkSurfaceKHR surface, VulkanDebugger& vkcppDebugger);
    VkPhysicalDevice getPhysicalDevice(){return physicalDevice;}
    VkDevice getLogicalDevice(){return device;}
    VkQueue getGraphicsQueue(){return graphicsQueue;}
    VkQueue getPresentQueue(){return presentQueue;}
    QueueFamilyIndices getQueueFamilyIndices(){return indices;}

private:
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;
    VkQueue graphicsQueue;
    VkQueue presentQueue;
    QueueFamilyIndices indices;
    void pickPhysicalDevice(VkInstance instance, VkSurfaceKHR surface);
    void createLogicalDevice(VkSurfaceKHR surface, VulkanDebugger& vkcppDebugger);
    const std::vector<const char*> deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
    };
};


}


#endif