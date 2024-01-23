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
    bool framebufferResized = false;
private:
    uint32_t WIDTH;
    uint32_t HEIGHT;
    static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
    GLFWwindow* window;
}
;

}

#endif