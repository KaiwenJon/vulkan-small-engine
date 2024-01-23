#ifndef VULKANUNIFORMBUFFER_H
#define VULKANUNIFORMBUFFER_H

#include "VulkanBuffer.h"
#include <cstring>

namespace vkcpp{
class VulkanDevice;
class VulkanUniformBuffer  : public VulkanBuffer{
public:
    VulkanUniformBuffer(VulkanDevice& vkcppDevice) : VulkanBuffer(vkcppDevice){};
    ~VulkanUniformBuffer();
    VulkanUniformBuffer(const VulkanUniformBuffer& other) = delete;
    VulkanUniformBuffer& operator=(const VulkanUniformBuffer& other) = delete;
    VulkanUniformBuffer(VulkanUniformBuffer&& other) : VulkanBuffer(std::move(other)) {
        uniformBufferMapped = other.uniformBufferMapped;
    }


    void createUniformBuffer(VkDeviceSize size);
    
    // template implementation needs to be seen by whoever calls it.
    template <typename T>
    void updateUniform(const T& newData){
        if(sizeof(T) > bufferSize){
            throw std::runtime_error("Uniform buffer update failed: data size is larger than allocated buffer size.");
        }
        memcpy(uniformBufferMapped, &newData, sizeof(T));
    }

private:
    void* uniformBufferMapped;

}


;

}

#endif