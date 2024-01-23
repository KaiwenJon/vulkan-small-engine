#include "VulkanResource.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstring>

namespace vkcpp{

std::vector<const char*> getRequiredExtensions(bool enableValidationLayers) {
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

    if (enableValidationLayers) {
        extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    }

    return extensions;
}

void VulkanResource::init(GLFWwindow* window){
    createInstance();
    vkcppDebugger.setup(instance);
    vkcppDevice.setup(instance, vkcppDebugger, window);
    vkcppCmdManager.init();
}

VulkanResource::VulkanResource()
{
}

VulkanResource::~VulkanResource()
{
    if(vkcppDevice.getSurface()!=VK_NULL_HANDLE) vkDestroySurfaceKHR(instance, vkcppDevice.getSurface(), nullptr);
    if(instance!=VK_NULL_HANDLE) vkDestroyInstance(instance, nullptr);
}

void VulkanResource::createInstance(){
    vkcppDebugger.checkValidationLayerSupport();

    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "vkcpp app";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    auto extensions = getRequiredExtensions(vkcppDebugger.enableValidationLayers);
    createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
    createInfo.ppEnabledExtensionNames = extensions.data();

    VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
    if (vkcppDebugger.enableValidationLayers) {
        createInfo.enabledLayerCount = static_cast<uint32_t>(vkcppDebugger.validationLayers.size());
        createInfo.ppEnabledLayerNames = vkcppDebugger.validationLayers.data();

        vkcppDebugger.populateDebugMessengerCreateInfo(debugCreateInfo);
        createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*) &debugCreateInfo;
    } else {
        createInfo.enabledLayerCount = 0;

        createInfo.pNext = nullptr;
    }

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        throw std::runtime_error("failed to create instance!");
    }
}


}