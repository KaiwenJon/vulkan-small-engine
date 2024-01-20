#include "VulkanApp.h"


namespace vkcpp{

void VulkanApp::run(){
    vkcppWindow.init();
    vkcppResource.init(vkcppWindow.getGLFWwindow());
    vkcppRenderer.init(vkcppResource, vkcppWindow);
}

}