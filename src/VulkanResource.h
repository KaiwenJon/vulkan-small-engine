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
        VulkanResource(GLFWwindow *window)
        {
            createInstance();
            vkcppDebugger.setup(instance);
            vkcppDevice.setup(instance, vkcppDebugger, window);
            vkcppCmdManager.init();
        };
        ~VulkanResource();
        VulkanResource(const VulkanResource &other) = delete;
        VulkanResource &operator=(const VulkanResource &other) = delete;
        void init(GLFWwindow *window);
        VulkanDevice &getDevice() { return vkcppDevice; }

    private:
        void createInstance();
        VkInstance instance;
        VulkanDebugger vkcppDebugger;
        VulkanDevice vkcppDevice;
        VulkanCommandManager vkcppCmdManager{vkcppDevice};
    };
};

#endif