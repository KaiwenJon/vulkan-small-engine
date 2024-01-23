#ifndef VULKANAPP_H
#define VULKANAPP_H

#define GLFW_INCLUDE_VULKAN
#include "VulkanWindow.h"
#include "VulkanResource.h"
#include "VulkanDebugger.h"
#include "VulkanRenderer.h"

namespace vkcpp{
class VulkanApp {
public:
    VulkanApp();
    ~VulkanApp();
    VulkanApp(const VulkanApp& other) = delete;
    VulkanApp& operator=(const VulkanApp& other) = delete;
    void run();

private:
    VulkanWindow vkcppWindow{800, 600};
    VulkanResource vkcppResource;
    VulkanRenderer vkcppRenderer{vkcppResource, vkcppWindow.framebufferResized};
};
}

#endif // VULKANAPP_H
