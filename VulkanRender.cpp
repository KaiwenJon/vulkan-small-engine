#include "VulkanRenderer.h"

namespace vkcpp{

void VulkanRenderer::init(VulkanResource& vkcppResource, VulkanWindow& vkcppWindow){
    createSwapChain();
    createImageViews();
    createRenderPass();
    createDescriptorSetLayout();
}


}