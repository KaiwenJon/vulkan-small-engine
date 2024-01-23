#ifndef VULKANSYNCOBJ_H
#define VULKANSYNCOBJ_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vector>

#include <VulkanDevice.h>

namespace vkcpp{

class VulkanSyncObj{
public:
    VulkanSyncObj(VulkanDevice& vkcppDevice) : vkcppDevice(vkcppDevice){};
    ~VulkanSyncObj();
    VulkanSyncObj(const VulkanSyncObj& other) = delete;
    VulkanSyncObj& operator=(const VulkanSyncObj& other) = delete;

    void create();
    void waitFence();
    void resetFence();
    VkSemaphore imageAvailableSemaphore;
    VkSemaphore renderFinishedSemaphore;
    VkFence inFlightFence;

private:
    VulkanDevice& vkcppDevice;


}
;
}
#endif