#ifndef VULKANPIPELINE_H
#define VULKANPIPELINE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "VulkanSwapChain.h"
#include "VulkanDevice.h"

namespace vkcpp{

class VulkanPipeline{
public:
    VulkanPipeline(VulkanDevice& vkcppDevice) : vkcppDevice(vkcppDevice){};
    ~VulkanPipeline();
    VulkanPipeline(const VulkanPipeline& other) = delete;
    VulkanPipeline& operator=(const VulkanPipeline& other) = delete;

    void createPipeline(VulkanSwapChain& vkcppSwapChain, VkDescriptorSetLayout descriptorSetLayout);
    VkPipelineLayout getPipelineLayout(){return pipelineLayout;}
    VkPipeline getGraphicsPipeline(){return graphicsPipeline;}
private:
    VulkanDevice& vkcppDevice;
    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;
}
;
}
#endif