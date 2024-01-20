#include "VulkanApp.h"


namespace vkcpp{

void VulkanApp::run(){
    vkcppWindow.init();
    vkcppResource.init(vkcppWindow.window);
    vkcppRenderer.init(vkcppResource, vkcppWindow);
}

}