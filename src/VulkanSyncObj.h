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

    void create(int numFrames);

private:
    VulkanDevice& vkcppDevice;

    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;

}
;
}
#endif