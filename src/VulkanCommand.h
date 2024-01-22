#ifndef VULKANCOMMAND_H
#define VULKANCOMMAND

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "VulkanDevice.h"

namespace vkcpp{

class VulkanCommandManager{
public:
    VulkanCommandManager();
    ~VulkanCommandManager();
    VulkanCommandManager(const VulkanCommandManager& other) = delete;
    VulkanCommandManager& operator=(const VulkanCommandManager& other) = delete;

    void init(VulkanDevice vkcppDevice);

private:
    VkCommandPool commandPool;
}
;
}

#endif