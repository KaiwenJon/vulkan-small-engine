#ifndef VULKANIMAGEUTILS_H
#define VULKANIMAGEUTILS_H


#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "VulkanDevice.h"
#include "VulkanCommand.h"

namespace vkcpp{

void createImage(
    VulkanDevice& vkcppDevice,
    uint32_t width, 
    uint32_t height, 
    uint32_t mipLevels, 
    VkSampleCountFlagBits numSamples, 
    VkFormat format, 
    VkImageTiling tiling, 
    VkImageUsageFlags usage, 
    VkMemoryPropertyFlags properties, 
    VkImage& image, 
    VkDeviceMemory& imageMemory
);

VkImageView createImageView(
    VkDevice device, 
    VkImage image, 
    VkFormat format, 
    VkImageAspectFlags aspectFlags, 
    uint32_t mipLevels
);

VkFormat findDepthFormat(VkPhysicalDevice physicalDevice);

VkFormat findSupportedFormat(
    VkPhysicalDevice physicalDevice, 
    const std::vector<VkFormat>& candidates, 
    VkImageTiling tiling, 
    VkFormatFeatureFlags features
);

VkSampleCountFlagBits getMaxUsableSampleCount(VkPhysicalDevice physicalDevice);

void generateMipmaps(
    VulkanCommandManager& vkcppCmdManager, 
    VkPhysicalDevice physicalDevice, 
    VkImage image, 
    VkFormat imageFormat, 
    int32_t texWidth, 
    int32_t texHeight, 
    uint32_t mipLevels
);
}

#endif