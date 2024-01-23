#ifndef VULKANCOMMAND_H
#define VULKANCOMMAND

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "VulkanDevice.h"

namespace vkcpp{

class VulkanCommandManager{
public:
    VulkanCommandManager(VulkanDevice& vkcppDevice) : vkcppDevice(vkcppDevice){}
    ~VulkanCommandManager();
    VulkanCommandManager(const VulkanCommandManager& other) = delete;
    VulkanCommandManager& operator=(const VulkanCommandManager& other) = delete;

    void init();
    void createCommandBuffersRender(int numFrames);
    VkCommandBuffer beginSingleTimeCommands();
    void endSingleTimeCommands(VkCommandBuffer commandBuffer);

private:
    VulkanDevice& vkcppDevice;
    VkCommandPool commandPool;
    std::vector<VkCommandBuffer> commandBuffers;

}
;
}

#endif