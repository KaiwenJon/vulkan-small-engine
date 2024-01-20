#ifndef VULKANWINDOW_H
#define VULKANWINDOW_H
#include <GLFW/glfw3.h>

namespace vkcpp{

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class VulkanWindow{
public:
    GLFWwindow* window;
    VulkanWindow(int w, int h): WIDTH(w), HEIGHT(h) {};
    ~VulkanWindow();
    VulkanWindow(const VulkanWindow& other) = delete;
    VulkanWindow& operator=(const VulkanWindow& other) = delete;

    void init();
    const uint32_t WIDTH;
    const uint32_t HEIGHT;
    bool framebufferResized = false;

private:
    // VkDebugUtilsMessengerEXT debugMessenger;
    // VkSurfaceKHR surface;
}
;

}

#endif