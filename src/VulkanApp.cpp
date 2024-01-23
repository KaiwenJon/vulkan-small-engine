#include "VulkanApp.h"


namespace vkcpp{
    VulkanApp::VulkanApp()
    {
    }

    VulkanApp::~VulkanApp()
    {
    }

void VulkanApp::run(){
    vkcppWindow.init();
    GLFWwindow* window = vkcppWindow.getGLFWwindow();
    vkcppResource.init(window);// need to received the updated window
    vkcppRenderer.init(window);// need to received the updated window

    vkcppRenderer.loop(window);
}

}