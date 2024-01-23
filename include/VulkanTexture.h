#ifndef VULKANTEXTURE_H
#define VULKANTEXTURE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "VulkanCommand.h"

#include <string>

namespace vkcpp{
class VulkanDevice;
class VulkanTexture{
public:
    VulkanTexture(VulkanDevice& vkcppDevice) : vkcppDevice(vkcppDevice){};
    ~VulkanTexture();
    VulkanTexture(const VulkanTexture& other) = delete;
    VulkanTexture& operator=(const VulkanTexture& other) = delete;
    
    void createTexture(VulkanCommandManager& vkcppCmdManager, const std::string& texture_path);
    VkImageView getTextureImageView(){return textureImageView;}
    VkSampler getTextureSampler(){return textureSampler;}
private:
    VulkanDevice& vkcppDevice;

    // one texture per manager for now
    uint32_t mipLevels;
    VkImage textureImage = VK_NULL_HANDLE;
    VkDeviceMemory textureImageMemory = VK_NULL_HANDLE;
    VkImageView textureImageView = VK_NULL_HANDLE;
    VkSampler textureSampler = VK_NULL_HANDLE;
}
;

}


#endif