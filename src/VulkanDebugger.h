#ifndef VULKANDEBUGGER_H
#define VULKANDEBUGGER_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>

namespace vkcpp{

class VulkanDebugger{
public:
    VulkanDebugger(VkInstance instance) : instance(instance){};
    ~VulkanDebugger();
    VulkanDebugger(const VulkanDebugger& other) = delete;
    VulkanDebugger& operator=(const VulkanDebugger& other) = delete;

    void setup(VkInstance instance);
    void checkValidationLayerSupport();
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    #ifdef NDEBUG
    const bool enableValidationLayers = false;
    #else
    const bool enableValidationLayers = true;
    #endif
    const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };


private:
    VkDebugUtilsMessengerEXT debugMessenger;
    VkInstance& instance;
};

;
}

#endif