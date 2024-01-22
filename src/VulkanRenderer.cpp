#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "VulkanRenderer.h"
#include "VulkanDevice.h"
#include "utils.h"
namespace vkcpp{

void VulkanRenderer::init(){
    vkcppSwapChain.init();
    vkcppDescriptorManager.createLayout();
    vkcppPipeline.createPipeline(vkcppResource.getDevice().getLogicalDevice(), vkcppSwapChain, vkcppDescriptorManager.getLayout());
    
}

void VulkanRenderer::drawFrame(){

}

}