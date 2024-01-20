#ifndef VULKANRENDERER_H
#define VULKANRENDERER_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "VulkanResource.h"
#include "VulkanWindow.h"

namespace vkcpp{

class VulkanRenderer{
public:
    VulkanRenderer();
    ~VulkanRenderer();
    VulkanRenderer(const VulkanRenderer& other) = delete;
    VulkanRenderer& operator=(const VulkanRenderer& other) = delete;

    void init(VulkanResource& vkcppResource, VulkanWindow& vkcppWindow);
private:
    
}
;
};

#endif