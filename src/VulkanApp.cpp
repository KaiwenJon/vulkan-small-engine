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
    vkcppResource.init();
    vkcppRenderer.init();

    vkcppRenderer.loop();
}

}