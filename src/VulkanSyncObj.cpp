#include "VulkanSyncObj.h"
#include "VulkanDevice.h"
#include  <stdexcept>


namespace vkcpp{
VulkanSyncObj::~VulkanSyncObj()
{
    VkDevice device = vkcppDevice.getLogicalDevice();
    vkDestroySemaphore(device, renderFinishedSemaphore, nullptr);
    vkDestroySemaphore(device, imageAvailableSemaphore, nullptr);
    vkDestroyFence(device, inFlightFence, nullptr);
}

void vkcpp::VulkanSyncObj::create(){
    VkDevice device = vkcppDevice.getLogicalDevice();

    VkSemaphoreCreateInfo semaphoreInfo{};
    semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

    VkFenceCreateInfo fenceInfo{};
    fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

    
    if (vkCreateSemaphore(device, &semaphoreInfo, nullptr, &imageAvailableSemaphore) != VK_SUCCESS ||
        vkCreateSemaphore(device, &semaphoreInfo, nullptr, &renderFinishedSemaphore) != VK_SUCCESS ||
        vkCreateFence(device, &fenceInfo, nullptr, &inFlightFence) != VK_SUCCESS) {
        throw std::runtime_error("failed to create synchronization objects for a frame!");
    }
    
}

void VulkanSyncObj::waitFence()
{
    vkWaitForFences(vkcppDevice.getLogicalDevice(), 1, &inFlightFence, VK_TRUE, UINT64_MAX);
}
void VulkanSyncObj::resetFence()
{
    vkResetFences(vkcppDevice.getLogicalDevice(), 1, &inFlightFence);

}
}