#ifndef VULKANTEXTURE_H
#define VULKANTEXTURE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "VulkanDevice.h"
#include "VulkanCommand.h"

#include <string>

namespace vkcpp{

class VulkanTexture{
public:
    VulkanTexture(VulkanDevice& vkcppDevice) : vkcppDevice(vkcppDevice){};
    ~VulkanTexture();
    VulkanTexture(const VulkanTexture& other) = delete;
    VulkanTexture& operator=(const VulkanTexture& other) = delete;
    
    void createTexture(VulkanCommandManager& vkcppCmdManager, const std::string& texture_path);
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