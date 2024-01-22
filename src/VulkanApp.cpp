#include "VulkanApp.h"


namespace vkcpp{

void VulkanApp::run(){
    vkcppWindow.init();
    vkcppResource.init();
    vkcppRenderer.init();
}

}