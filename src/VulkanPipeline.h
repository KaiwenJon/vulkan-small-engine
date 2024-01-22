#ifndef VULKANPIPELINE_H
#define VULKANPIPELINE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "VulkanSwapChain.h"

namespace vkcpp{

class VulkanPipeline{
public:
    VulkanPipeline();
    ~VulkanPipeline();
    VulkanPipeline(const VulkanPipeline& other) = delete;
    VulkanPipeline& operator=(const VulkanPipeline& other) = delete;

    void createPipeline(VkDevice device, VulkanSwapChain& vkcppSwapChain, VkDescriptorSetLayout descriptorSetLayout);
private:
    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;
}
;
}
#endif