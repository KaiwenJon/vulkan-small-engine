#ifndef VULKANUNIFORMBUFFER_H
#define VULKANUNIFORMBUFFER_H

#include "VulkanBuffer.h"

namespace vkcpp{

class VulkanUniformBuffer  : public VulkanBuffer{
public:
    VulkanUniformBuffer(VulkanDevice& vkcppDevice) : VulkanBuffer(vkcppDevice){};
    ~VulkanUniformBuffer();
    VulkanUniformBuffer(const VulkanUniformBuffer& other) = delete;
    VulkanUniformBuffer& operator=(const VulkanUniformBuffer& other) = delete;

    void createUniformBuffer(VkDeviceSize size);
    
    template <typename T>
    void updateUniform(const T& newData);

private:
    void* uniformBufferMapped;

}


;

}

#endif