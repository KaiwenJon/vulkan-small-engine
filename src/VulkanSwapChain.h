#ifndef VULKANSWAPCHAIN_H
#define VULKANSWAPCHAIN

#include "VulkanResource.h"
#include "VulkanWindow.h"

namespace vkcpp{

class VulkanSwapChain{
public:
    VulkanSwapChain();
    ~VulkanSwapChain();
    VulkanSwapChain(const VulkanSwapChain& other) = delete;
    VulkanSwapChain& operator=(const VulkanSwapChain& other) = delete;

    void init(VulkanResource& vkcppResource, VulkanWindow& vkcppWindow);
    VkSwapchainKHR getSwapChain(){return swapChain;}
    VkRenderPass getRenderPass(){return renderPass;}
    VkSampleCountFlagBits getMsaaSamples(){return msaaSamples;}
private:
    void createSwapChain(VulkanDevice& vkcppDevice, VkSurfaceKHR surface, GLFWwindow* window);
    void createImageViews(VulkanDevice& vkcppDevice);
    void createRenderPass(VulkanDevice& vkcppDevice);
    void createColorResources(VulkanDevice& vkcppDevice);
    void createDepthResources(VulkanDevice& vkcppDevice);
    void createFramebuffers(VkDevice device);
    void createTextureImage(VulkanDevice& vkcppDevice, const std::string& texture_path);
    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImageView> swapChainImageViews;
    std::vector<VkFramebuffer> swapChainFramebuffers;
    VkSampleCountFlagBits msaaSamples = VK_SAMPLE_COUNT_1_BIT;
    VkRenderPass renderPass;

    VkImage colorImage;
    VkDeviceMemory colorImageMemory;
    VkImageView colorImageView;

    VkImage depthImage;
    VkDeviceMemory depthImageMemory;
    VkImageView depthImageView;

    uint32_t mipLevels;
    VkImage textureImage;
    VkDeviceMemory textureImageMemory;
    VkImageView textureImageView;
    VkSampler textureSampler;
}
;
}
#endif
