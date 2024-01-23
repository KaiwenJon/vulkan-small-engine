#ifndef VULKANSYNCOBJ_H
#define VULKANSYNCOBJ_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vector>


namespace vkcpp{
class VulkanDevice;
class VulkanSyncObj{
public:
    VulkanSyncObj(VulkanDevice& vkcppDevice) : vkcppDevice(vkcppDevice){};
    ~VulkanSyncObj();
    VulkanSyncObj(const VulkanSyncObj& other) = delete;
    VulkanSyncObj& operator=(const VulkanSyncObj& other) = delete;
    VulkanSyncObj(VulkanSyncObj&& other) : vkcppDevice(other.vkcppDevice){
        imageAvailableSemaphore = other.imageAvailableSemaphore;
        renderFinishedSemaphore = other.renderFinishedSemaphore;
        inFlightFence = other.inFlightFence;
        other.imageAvailableSemaphore = VK_NULL_HANDLE;
        other.renderFinishedSemaphore = VK_NULL_HANDLE;
        other.inFlightFence = VK_NULL_HANDLE;
    }

    void create();
    void waitFence();
    void resetFence();
    VkSemaphore imageAvailableSemaphore = VK_NULL_HANDLE;
    VkSemaphore renderFinishedSemaphore = VK_NULL_HANDLE;
    VkFence inFlightFence = VK_NULL_HANDLE;

private:
    VulkanDevice& vkcppDevice;


}
;
}
#endif