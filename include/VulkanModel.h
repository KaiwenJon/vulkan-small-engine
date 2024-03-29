#ifndef VULKANMODEL_H
#define VULKANMODEL_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vector>
#include "VulkanDevice.h"
#include "VulkanBuffer.h"
#include "VulkanCommand.h"
#include "utils.h"


namespace vkcpp{


struct Vertex {
    glm::vec3 pos;
    glm::vec3 color;
    glm::vec2 texCoord;

    static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
    static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();

    bool operator==(const Vertex& other) const{
        return pos == other.pos && color == other.color && texCoord == other.texCoord;
    }
};
class VulkanCommandManager;
class VulkanBuffer;
class VulkanModel{

public:

    VulkanModel(VulkanDevice& vkcppDevice) : vkcppDevice(vkcppDevice){};
    ~VulkanModel();
    VulkanModel(const VulkanModel& other) = delete;
    VulkanModel& operator=(const VulkanModel& other) = delete;

    void loadModel(VulkanCommandManager& vkcppCmdManager, const std::string& model_path);
    VkBuffer getVertexBuffer(){return vkcppVertexBuffer.getBuffer();}
    VkBuffer getIndexBuffer(){return vkcppIndexBuffer.getBuffer();}
    int getIndiceSize() const {return indices.size();}
private:
    VulkanDevice& vkcppDevice;
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
    VulkanBuffer vkcppVertexBuffer{vkcppDevice};
    VulkanBuffer vkcppIndexBuffer{vkcppDevice};
}
;
}

#endif