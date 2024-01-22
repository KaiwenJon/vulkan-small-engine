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
    VulkanRenderer(VulkanResource& vkcppResource)
    :
    vkcppResource(vkcppResource),
    vkcppSwapChain(vkcppResource.getDevice()){}
    ;
    ~VulkanRenderer();
    VulkanRenderer(const VulkanRenderer& other) = delete;
    VulkanRenderer& operator=(const VulkanRenderer& other) = delete;

    void init(VulkanWindow& vkcppWindow);
    void drawFrame();
private:
    VulkanResource& vkcppResource;
    VulkanSwapChain vkcppSwapChain;
    VulkanPipeline vkcppPipeline;
    void createDescriptorSetLayout(VulkanDevice& vkcppDevice);
    VkDescriptorSetLayout descriptorSetLayout;
}
;
};

#endif