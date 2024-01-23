#ifndef VULKANSWAPCHAIN_H
#define VULKANSWAPCHAIN_H

namespace vkcpp{
class VulkanDevice;
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
    void recreate();
    uint32_t getNextImageIdx(VkSemaphore imageAvailableSemaphore);
    void present();
    VkSwapchainKHR getSwapChain(){return swapChain;}
    VkRenderPass getRenderPass(){return renderPass;}
    VkSampleCountFlagBits getMsaaSamples(){return msaaSamples;}
    VkExtent2D getExtent(){return swapChainExtent;}
    std::vector<VkFramebuffer>& getFrameBuffers(){return swapChainFramebuffers;}
private:
    void createSwapChain();
    void createImageViews();
    void createRenderPass();
    void createColorResources();
    void createDepthResources();
    void createFramebuffers();
    void cleanup();
    
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
