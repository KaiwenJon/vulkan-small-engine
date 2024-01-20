#ifndef VULKANWINDOW_H
#define VULKANWINDOW_H
#include <GLFW/glfw3.h>

namespace vkcpp{

class VulkanWindow{
public:
    VulkanWindow(int w, int h): WIDTH(w), HEIGHT(h) {};
    ~VulkanWindow();
    VulkanWindow(const VulkanWindow& other) = delete;
    VulkanWindow& operator=(const VulkanWindow& other) = delete;

    void init();
    GLFWwindow *getGLFWwindow() const { return window; }
private:
    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;
    static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
    GLFWwindow* window;
    bool framebufferResized = false;
}
;

}

#endif