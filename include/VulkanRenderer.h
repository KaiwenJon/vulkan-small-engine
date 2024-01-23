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
#include "VulkanTexture.h"
#include "VulkanDescriptorManager.h"
#include "VulkanSyncObj.h"
#include "VulkanModel.h"
#include "VulkanUniformBuffer.h"

namespace vkcpp{
class VulkanCommandManager;
class VulkanRenderer{
public:
    VulkanRenderer(VulkanResource& vkcppResource, bool& frameBufferResizedRef)
    :
    frameBufferResizedRef(frameBufferResizedRef),
    vkcppResource(vkcppResource),
    vkcppCmdManager(vkcppResource.getCmdManager()),
    vkcppSwapChain(vkcppResource.getDevice()),
    vkcppTexture(vkcppResource.getDevice()),
    vkcppPipeline(vkcppResource.getDevice()),
    vkcppDescriptorManager(vkcppResource.getDevice()),
    vkcppModel(vkcppResource.getDevice())
    
    // vkcppSyncObjs(std::move(std::vector<VulkanSyncObj>(numFrames, VulkanSyncObj(vkcppResource.getDevice())))),
    // vkcppUniformBuffers(std::move(std::vector<VulkanUniformBuffer>(numFrames, VulkanUniformBuffer(vkcppResource.getDevice()))))
    {
        // initializer list, use copy
        // use emplace back and define move construct
        for(int i=0; i<numFrames; i++){
            vkcppSyncObjs.emplace_back(vkcppResource.getDevice());
            vkcppUniformBuffers.emplace_back(vkcppResource.getDevice());
        }
        
    }
    ;
    ~VulkanRenderer();
    VulkanRenderer(const VulkanRenderer& other) = delete;
    VulkanRenderer& operator=(const VulkanRenderer& other) = delete;

    void init(GLFWwindow* window);
    void loop(GLFWwindow* window);
    void drawFrame();
private:
    // resources from others
    VulkanResource& vkcppResource;
    VulkanCommandManager& vkcppCmdManager;
    bool& frameBufferResizedRef;

    // Renderer's resources
    VulkanSwapChain vkcppSwapChain;
    VulkanTexture vkcppTexture;
    VulkanPipeline vkcppPipeline;
    VulkanDescriptorManager vkcppDescriptorManager;
    VulkanModel vkcppModel;

    // resources for all flying frames
    int cur_resource_idx = 0;
    void initResourcesAllFrames();
    void updateUniformBuffer(int cur_resource_idx);
    int numFrames = 3;
    std::vector<VulkanSyncObj> vkcppSyncObjs;
    std::vector<VulkanUniformBuffer> vkcppUniformBuffers;
}
;
};

#endif