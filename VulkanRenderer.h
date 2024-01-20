#ifndef VULKANRENDERER_H
#define VULKANRENDERER_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>

#include "VulkanResource.h"
#include "VulkanWindow.h"
#include "VulkanSwapChain.h"
#include "VulkanPipeline.h"

namespace vkcpp{

class VulkanRenderer{
public:
    VulkanRenderer();
    ~VulkanRenderer();
    VulkanRenderer(const VulkanRenderer& other) = delete;
    VulkanRenderer& operator=(const VulkanRenderer& other) = delete;

    void init(VulkanResource& vkcppResource, VulkanWindow& vkcppWindow);
private:
    VulkanSwapChain vkcppSwapChain;
    VulkanPipeline vkcppPipeline;
    void createDescriptorSetLayout(VulkanDevice& vkcppDevice);
    VkDescriptorSetLayout descriptorSetLayout;
}
;
};

#endif