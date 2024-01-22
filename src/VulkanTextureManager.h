#ifndef VULKANTEXTUREMANAGER_H
#define VULKANTEXTUREMANAGER_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "VulkanDevice.h"
#include "VulkanCommand.h"

#include <string>

namespace vkcpp{

class VulkanTextureManager{
public:
    VulkanTextureManager(VulkanDevice& vkcppDevice) : vkcppDevice(vkcppDevice){};
    ~VulkanTextureManager();
    VulkanTextureManager(const VulkanTextureManager& other) = delete;
    VulkanTextureManager& operator=(const VulkanTextureManager& other) = delete;
    
    void createTextureImage(VulkanCommandManager& vkcppCmdManager, const std::string& texture_path);
private:
    VulkanDevice& vkcppDevice;

    // one texture per manager for now
    uint32_t mipLevels;
    VkImage textureImage;
    VkDeviceMemory textureImageMemory;
    VkImageView textureImageView;
    VkSampler textureSampler;
}
;

}


#endif