#ifndef VULKANDEVICE_H
#define VULKANDEVICE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "utils.h"

namespace vkcpp{
class VulkanDebugger;
class VulkanDevice{
public:
    VulkanDevice();
    ~VulkanDevice();
    VulkanDevice(const VulkanDevice& other) = delete;
    VulkanDevice& operator=(const VulkanDevice& other) = delete;
    void setup(VkInstance instance, VulkanDebugger& vkcppDebugger, GLFWwindow* window);
    VkPhysicalDevice getPhysicalDevice(){return physicalDevice;}
    VkDevice getLogicalDevice(){return device;}
    VkQueue getGraphicsQueue(){return graphicsQueue;}
    VkQueue getPresentQueue(){return presentQueue;}
    QueueFamilyIndices getQueueFamilyIndices(){return indices;}
    VkSurfaceKHR getSurface(){return surface;}

private:
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;
    VkSurfaceKHR surface;
    VkQueue graphicsQueue;
    VkQueue presentQueue;
    QueueFamilyIndices indices;
    void pickPhysicalDevice(VkInstance instance);
    void createLogicalDevice(VulkanDebugger& vkcppDebugger);
    const std::vector<const char*> deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
    };
};


}


#endif