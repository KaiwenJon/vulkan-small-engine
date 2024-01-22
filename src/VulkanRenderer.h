#ifndef VULKANRENDERER_H
#define VULKANRENDERER_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>
#include <memory>

#include "VulkanResource.h"
#include "VulkanWindow.h"
#include "VulkanSwapChain.h"
#include "VulkanPipeline.h"

namespace vkcpp{

class VulkanRenderer{
public:
    VulkanRenderer(VulkanResource& vkcppResource, GLFWwindow* window)
    :
    window(window),
    vkcppResource(vkcppResource),
    vkcppSwapChain(vkcppResource.getDevice(), window),
    vkcppCmdManager(vkcppResource.getCmdManager())
    {}
    ;
    ~VulkanRenderer();
    VulkanRenderer(const VulkanRenderer& other) = delete;
    VulkanRenderer& operator=(const VulkanRenderer& other) = delete;

    void init();
    void drawFrame();
private:
    // resources from others
    GLFWwindow* window;
    VulkanResource& vkcppResource;
    VulkanCommandManager& vkcppCmdManager;

    // Renderer's resources
    VulkanSwapChain vkcppSwapChain;
    VulkanPipeline vkcppPipeline;
    void createDescriptorSetLayout(VulkanDevice& vkcppDevice);
    VkDescriptorSetLayout descriptorSetLayout;
}
;
};

#endif