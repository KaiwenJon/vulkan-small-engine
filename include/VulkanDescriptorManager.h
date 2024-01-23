#ifndef VULKANDESCRIPTORMANAGER_H
#define VULKANDESCRIPTORMANAGER_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "VulkanUniformBuffer.h"
#include "VulkanTexture.h"

namespace vkcpp{
class VulkanDevice;
class VulkanDescriptorManager{
public:
    VulkanDescriptorManager(VulkanDevice& vkcppDevice) : vkcppDevice(vkcppDevice){};
    ~VulkanDescriptorManager();
    VulkanDescriptorManager(const VulkanDescriptorManager& other) = delete;
    VulkanDescriptorManager& operator=(const VulkanDescriptorManager& other) = delete;

    void createLayout();
    void createPool(int uboCnt, int texCnt, int maxSets);
    void createSameDescriptorSets(int numSets);
    template<typename T> void bindUniform(VulkanUniformBuffer& vkcppUniformBuffer, int setIdx, int binding);
    void bindTexture(VulkanTexture& vkcppTexture, int setIdx, int binding);
    VkDescriptorSetLayout getLayout(){return descriptorSetLayout;}
    std::vector<VkDescriptorSet>& getDescriptorSets(){return descriptorSets;}

private:
    VulkanDevice& vkcppDevice;
    VkDescriptorSetLayout descriptorSetLayout;
    VkDescriptorPool descriptorPool;
    std::vector<VkDescriptorSet> descriptorSets;
}

;
}

#endif