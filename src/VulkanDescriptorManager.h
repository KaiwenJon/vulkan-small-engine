#ifndef VULKANDESCRIPTORMANAGER_H
#define VULKANDESCRIPTORMANAGER_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "VulkanDevice.h"
#include "VulkanUniformBuffer.h"
#include "VulkanTextureManager.h"

namespace vkcpp{

class VulkanDescriptorManager{
public:
    VulkanDescriptorManager(VulkanDevice& vkcppDevice) : vkcppDevice(vkcppDevice){};
    ~VulkanDescriptorManager();
    VulkanDescriptorManager(const VulkanDescriptorManager& other) = delete;
    VulkanDescriptorManager& operator=(const VulkanDescriptorManager& other) = delete;

    void createLayout();
    void createPool(int numFrames);

    template<typename T>
    void createDescriptorSetsUniform(int numFrames, VulkanUniformBuffer& vkcppUniformBuffer);
    void createDescriptorSetsTexture(VulkanTexture& vkcppTextureManager);
    VkDescriptorSetLayout getLayout(){return descriptorSetLayout;}

private:
    VulkanDevice& vkcppDevice;
    VkDescriptorSetLayout descriptorSetLayout;
    VkDescriptorPool descriptorPool;
    std::vector<VkDescriptorSet> descriptorSets;
}

;
}

#endif