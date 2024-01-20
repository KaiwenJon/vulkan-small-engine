#ifndef VULKANRENDERER_H
#define VULKANRENDERER_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>

#include "VulkanResource.h"
#include "VulkanWindow.h"

namespace vkcpp{

class VulkanRenderer{
public:
    VulkanRenderer();
    ~VulkanRenderer();
    VulkanRenderer(const VulkanRenderer& other) = delete;
    VulkanRenderer& operator=(const VulkanRenderer& other) = delete;

    void init(VulkanResource& vkcppResource, VulkanWindow& vkcppWindow);
private:
    void createSwapChain(VulkanDevice& vkcppDevice, VkSurfaceKHR surface, GLFWwindow* window);
    void createImageViews(VulkanDevice& vkcppDevice);
    void createRenderPass(VulkanDevice& vkcppDevice);
    void createDescriptorSetLayout(VulkanDevice& vkcppDevice);
    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImageView> swapChainImageViews;
    std::vector<VkFramebuffer> swapChainFramebuffers;
    VkSampleCountFlagBits msaaSamples = VK_SAMPLE_COUNT_1_BIT;
    VkRenderPass renderPass;
    VkDescriptorSetLayout descriptorSetLayout;
}
;
};

#endif