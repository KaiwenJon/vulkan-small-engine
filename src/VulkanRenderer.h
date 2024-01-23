#ifndef VULKANRENDERER_H
#define VULKANRENDERER_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>
#include <memory>
#include <vector>

#include "VulkanResource.h"
#include "VulkanWindow.h"
#include "VulkanSwapChain.h"
#include "VulkanPipeline.h"
#include "VulkanCommand.h"
#include "VulkanTexture.h"
#include "VulkanDescriptorManager.h"
#include "VulkanSyncObj.h"
#include "VulkanModel.h"
#include "VulkanUniformBuffer.h"

namespace vkcpp{

class VulkanRenderer{
public:
    VulkanRenderer(VulkanResource& vkcppResource, VulkanWindow& vkcppWindow)
    :
    window(vkcppWindow.getGLFWwindow()),
    framebufferResized(vkcppWindow.framebufferResized),
    vkcppResource(vkcppResource),
    vkcppSwapChain(vkcppResource.getDevice(), window),
    vkcppCmdManager(vkcppResource.getCmdManager()),
    vkcppTexture(vkcppResource.getDevice()),
    vkcppDescriptorManager(vkcppResource.getDevice()),
    vkcppModel(vkcppResource.getDevice()),
    
    vkcppSyncObjs(numFrames, VulkanSyncObj(vkcppResource.getDevice())),
    vkcppUniformBuffers(numFrames, VulkanUniformBuffer(vkcppResource.getDevice()))
    {}
    ;
    ~VulkanRenderer();
    VulkanRenderer(const VulkanRenderer& other) = delete;
    VulkanRenderer& operator=(const VulkanRenderer& other) = delete;

    void init();
    void loop();
    void drawFrame();
private:
    // resources from others
    GLFWwindow* window;
    VulkanResource& vkcppResource;
    VulkanCommandManager& vkcppCmdManager;
    bool& framebufferResized;

    // Renderer's resources
    VulkanSwapChain vkcppSwapChain;
    VulkanTexture vkcppTexture;
    VulkanPipeline vkcppPipeline;
    VulkanDescriptorManager vkcppDescriptorManager;
    VulkanModel vkcppModel;

    // resources for all flying frames
    int cur_resource_idx = 0;
    void initResourcesAllFrames();
    void VulkanRenderer::updateUniformBuffer(int cur_resource_idx);
    int numFrames = 3;
    std::vector<VulkanSyncObj> vkcppSyncObjs;
    std::vector<VulkanUniformBuffer> vkcppUniformBuffers;
}
;
};

#endif