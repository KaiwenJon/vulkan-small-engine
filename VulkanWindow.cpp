#include "VulkanWindow.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace vkcpp{

void framebufferResizeCallback(GLFWwindow* window, int width, int height){
    auto win = reinterpret_cast<VulkanWindow*>(glfwGetWindowUserPointer(window));
    win->framebufferResized = true;
}

void VulkanWindow::init(){
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
}


}