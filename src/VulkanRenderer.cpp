#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/hash.hpp>

#include <chrono>
#include "VulkanRenderer.h"
#include "VulkanDevice.h"
#include "utils.h"
namespace vkcpp{

struct UniformBufferObject {
    alignas(16) glm::mat4 model;
    alignas(16) glm::mat4 view;
    alignas(16) glm::mat4 proj;
};

void VulkanRenderer::init(){
    vkcppSwapChain.init();
    vkcppDescriptorManager.createLayout();
    vkcppPipeline.createPipeline(vkcppSwapChain, vkcppDescriptorManager.getLayout());
    vkcppTexture.createTexture(vkcppCmdManager, "../resources/viking_rooom.png");
    vkcppModel.loadModel(vkcppCmdManager, "../resources/viking_rooom.obj");
    initResourcesAllFrames();
}

void VulkanRenderer::loop(){
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        drawFrame();
    }

    vkDeviceWaitIdle(vkcppResource.getDevice().getLogicalDevice());
}

void VulkanRenderer::initResourcesAllFrames(){
    vkcppDescriptorManager.createPool(numFrames, numFrames, numFrames);
    vkcppDescriptorManager.createSameDescriptorSets(numFrames);

    for(int i=0; i<numFrames; i++){
        // uniform buffers
        VkDeviceSize ubBufferSize = sizeof(UniformBufferObject);
        vkcppUniformBuffers[i].createUniformBuffer(ubBufferSize);

        // sync objects
        vkcppSyncObjs[i].create();

        // descriptor
        vkcppDescriptorManager.bindTexture(
            vkcppTexture,
            i,
            1
        );

        vkcppDescriptorManager.bindUniform<UniformBufferObject>(
            vkcppUniformBuffers[i],
            i,
            0
        );
    }
}

void VulkanRenderer::drawFrame(){
    VulkanDevice& vkcppDevice = vkcppResource.getDevice();
    vkcppSyncObjs[cur_resource_idx].waitFence();

    uint32_t imageIndex = vkcppSwapChain.getNextImageIdx(vkcppSyncObjs[cur_resource_idx].imageAvailableSemaphore);

    updateUniformBuffer(cur_resource_idx);

    vkcppSyncObjs[cur_resource_idx].resetFence();
    
    vkcppCmdManager.resetCmdBuffer(cur_resource_idx);
    
    vkcppCmdManager.recordDrawCmd(
        cur_resource_idx,
        imageIndex,
        vkcppModel,
        vkcppPipeline,
        vkcppSwapChain,
        vkcppDescriptorManager.getDescriptorSets()[cur_resource_idx]
    );
    
    VkResult result = vkcppCmdManager.submitDrawAndPresent(
        cur_resource_idx,
        imageIndex,
        vkcppSwapChain, 
        vkcppSyncObjs[cur_resource_idx]
    );

    if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR || framebufferResized) {
        framebufferResized = false;
        vkcppSwapChain.recreate();
    } else if (result != VK_SUCCESS) {
        throw std::runtime_error("failed to present swap chain image!");
    }

    cur_resource_idx = (cur_resource_idx + 1) % numFrames;
}

void VulkanRenderer::updateUniformBuffer(int cur_resource_idx){
    VkExtent2D swapChainExtent = vkcppSwapChain.getExtent();
    static auto startTime = std::chrono::high_resolution_clock::now();

    auto currentTime = std::chrono::high_resolution_clock::now();
    float time = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - startTime).count();

    UniformBufferObject ubo{};
    ubo.model = glm::rotate(glm::mat4(1.0f), time * glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    ubo.view = glm::lookAt(glm::vec3(2.0f, 2.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    ubo.proj = glm::perspective(glm::radians(45.0f), swapChainExtent.width / (float) swapChainExtent.height, 0.1f, 10.0f);
    ubo.proj[1][1] *= -1;

    vkcppUniformBuffers[cur_resource_idx].updateUniform<UniformBufferObject>(ubo);
}

}