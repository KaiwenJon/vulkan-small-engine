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
    void bindTexture(VulkanTexture& vkcppTexture, int setIdx, int binding);
    VkDescriptorSetLayout getLayout(){return descriptorSetLayout;}
    std::vector<VkDescriptorSet>& getDescriptorSets(){return descriptorSets;}

    template <typename T>
    void bindUniform(VulkanUniformBuffer& vkcppUniformBuffer, int setIdx, int binding)
    {
        VkDescriptorBufferInfo bufferInfo{};
        bufferInfo.buffer = vkcppUniformBuffer.getBuffer();
        bufferInfo.offset = 0;
        bufferInfo.range = sizeof(T);
        std::vector<VkWriteDescriptorSet> descriptorWrites(1);
        descriptorWrites[0].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        descriptorWrites[0].dstSet = descriptorSets[setIdx];
        descriptorWrites[0].dstBinding = binding;
        descriptorWrites[0].dstArrayElement = 0;
        descriptorWrites[0].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        descriptorWrites[0].descriptorCount = 1;
        descriptorWrites[0].pBufferInfo = &bufferInfo;
        vkUpdateDescriptorSets(vkcppDevice.getLogicalDevice(), static_cast<uint32_t>(descriptorWrites.size()), descriptorWrites.data(), 0, nullptr);
    }
private:
    VulkanDevice& vkcppDevice;
    VkDescriptorSetLayout descriptorSetLayout;
    VkDescriptorPool descriptorPool;
    std::vector<VkDescriptorSet> descriptorSets;
}

;
}

#endif