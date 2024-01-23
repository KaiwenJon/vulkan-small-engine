#ifndef VULKANRESOURCE_H
#define VULKANRESOURCE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "VulkanDebugger.h"
#include "VulkanDevice.h"
#include "VulkanCommand.h"

namespace vkcpp
{

    class VulkanResource
    {
    public:
        VulkanResource(GLFWwindow *window) : window(window){};
        ~VulkanResource();
        VulkanResource(const VulkanResource &other) = delete;
        VulkanResource &operator=(const VulkanResource &other) = delete;
        void init();
        VulkanDevice &getDevice() { return vkcppDevice; }
        VulkanCommandManager& getCmdManager(){return vkcppCmdManager;}
    private:
        void createInstance();
        GLFWwindow *window;
        VkInstance instance;
        VulkanDebugger vkcppDebugger{instance};
        VulkanDevice vkcppDevice;
        VulkanCommandManager vkcppCmdManager{vkcppDevice};
    };
};

#endif