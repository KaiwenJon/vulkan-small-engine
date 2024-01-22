#ifndef VULKANSWAPCHAIN_H
#define VULKANSWAPCHAIN

#include "VulkanResource.h"
#include "VulkanWindow.h"

namespace vkcpp{

class VulkanSwapChain{
public:
    VulkanSwapChain(VulkanDevice& vkcppDevice, GLFWwindow* window)
    :
    vkcppDevice(vkcppDevice),
    window(window)
    {};
    ~VulkanSwapChain();
    VulkanSwapChain(const VulkanSwapChain& other) = delete;
    VulkanSwapChain& operator=(const VulkanSwapChain& other) = delete;

    void init();
    VkSwapchainKHR getSwapChain(){return swapChain;}
    VkRenderPass getRenderPass(){return renderPass;}
    VkSampleCountFlagBits getMsaaSamples(){return msaaSamples;}
private:
    void createSwapChain();
    void createImageViews();
    void createRenderPass();
    void createColorResources();
    void createDepthResources();
    void createFramebuffers();
    void createTextureImage(const std::string& texture_path);
    
    GLFWwindow* window;
    VulkanDevice& vkcppDevice;

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

}
;
}
#endif
