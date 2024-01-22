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
#include "VulkanCommand.h"
#include "VulkanTextureManager.h"
#include "VulkanDescriptorManager.h"

namespace vkcpp{

class VulkanRenderer{
public:
    VulkanRenderer(VulkanResource& vkcppResource, GLFWwindow* window)
    :
    window(window),
    vkcppResource(vkcppResource),
    vkcppSwapChain(vkcppResource.getDevice(), window),
    vkcppCmdManager(vkcppResource.getCmdManager()),
    vkcppTextureManager(vkcppResource.getDevice()),
    vkcppDescriptorManager(vkcppResource.getDevice())
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
    VulkanTexture vkcppTextureManager;
    VulkanPipeline vkcppPipeline;
    VulkanDescriptorManager vkcppDescriptorManager;
}
;
};

#endif