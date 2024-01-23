#ifndef VULKANCOMMAND_H
#define VULKANCOMMAND_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "VulkanDevice.h"

namespace vkcpp{
class VulkanModel;
class VulkanPipeline;
class VulkanSwapChain;
class VulkanSyncObj;
class VulkanCommandManager{
public:
    VulkanCommandManager(VulkanDevice& vkcppDevice) : vkcppDevice(vkcppDevice){}
    ~VulkanCommandManager();
    VulkanCommandManager(const VulkanCommandManager& other) = delete;
    VulkanCommandManager& operator=(const VulkanCommandManager& other) = delete;

    void init();
    void resetCmdBuffer(int bufferIdx);
    void recordDrawCmd(
        int cur_resource_idx,
        uint32_t imageIndex,
        VulkanModel& vkcppModel,
        VulkanPipeline& vkcppPipeline,
        VulkanSwapChain& vkcppSwapChain,
        VkDescriptorSet descriptorSet
    );

    VkResult submitDrawAndPresent(
        int cur_resource_idx, 
        uint32_t imageIndex,
        VulkanSwapChain& vkcppSwapChain,
        VulkanSyncObj& vkcppSyncObj
    );
    void createCommandBuffersRender(int numFrames);
    VkCommandBuffer beginSingleTimeCommands();
    void endSingleTimeCommands(VkCommandBuffer commandBuffer);

private:
    VulkanDevice& vkcppDevice;
    VkCommandPool commandPool = VK_NULL_HANDLE;
    std::vector<VkCommandBuffer> commandBuffers;

}
;
}

#endif