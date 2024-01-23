#ifndef VULKANSWAPCHAIN_H
#define VULKANSWAPCHAIN_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>


namespace vkcpp{
class VulkanDevice;
class VulkanSwapChain{
public:
    VulkanSwapChain(VulkanDevice& vkcppDevice)
    :
    vkcppDevice(vkcppDevice)
    {};
    ~VulkanSwapChain();
    VulkanSwapChain(const VulkanSwapChain& other) = delete;
    VulkanSwapChain& operator=(const VulkanSwapChain& other) = delete;

    void init(GLFWwindow* window);
    void recreate();
    VkResult getNextImageIdx(VkSemaphore imageAvailableSemaphore, uint32_t& imageIndex);
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
    
    GLFWwindow* window; // created window, received when init
    VulkanDevice& vkcppDevice;

    VkSwapchainKHR swapChain = VK_NULL_HANDLE;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImageView> swapChainImageViews;
    std::vector<VkFramebuffer> swapChainFramebuffers;
    VkSampleCountFlagBits msaaSamples = VK_SAMPLE_COUNT_1_BIT;
    VkRenderPass renderPass = VK_NULL_HANDLE;

    VkImage colorImage = VK_NULL_HANDLE;
    VkDeviceMemory colorImageMemory = VK_NULL_HANDLE;
    VkImageView colorImageView = VK_NULL_HANDLE;

    VkImage depthImage = VK_NULL_HANDLE;
    VkDeviceMemory depthImageMemory = VK_NULL_HANDLE;
    VkImageView depthImageView = VK_NULL_HANDLE;

}
;
}
#endif
