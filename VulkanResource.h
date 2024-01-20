#ifndef VULKANRESOURCE_H
#define VULKANRESOURCE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "VulkanDebugger.h"
#include "VulkanDevice.h"

namespace vkcpp{

class VulkanResource{
public:
    VulkanResource();
    ~VulkanResource();
    VulkanResource(const VulkanResource& other) = delete;
    VulkanResource& operator=(const VulkanResource& other) = delete;
    void init(GLFWwindow* window);
    VulkanDevice& getDevice() {return vkcppDevice;}
    VkSurfaceKHR getSurface() {return surface;}
private:

    void createInstance();
    void createSurface(GLFWwindow* window);
    VkInstance instance;
    VkSurfaceKHR surface;
    VulkanDebugger vkcppDebugger;
    VulkanDevice vkcppDevice;
}
;
};

#endif