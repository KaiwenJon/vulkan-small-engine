#include "VulkanUniformBuffer.h"

namespace vkcpp{


void VulkanUniformBuffer::createUniformBuffer(VkDeviceSize size){
    createBuffer(
        size, 
        VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, 
        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, 
        buffer, 
        bufferMemory
    );

    vkMapMemory(
        vkcppDevice.getLogicalDevice(), 
        bufferMemory, 
        0, 
        size, 
        0, 
        &uniformBufferMapped
    );

}

template <typename T>
void VulkanUniformBuffer::updateUniform(const T& newData){
    if(sizeof(T) > bufferSize){
        throw std::runtime_error("Uniform buffer update failed: data size is larger than allocated buffer size.");
    }
    memcpy(uniformBufferMapped, &newData, sizeof(T));
}


}