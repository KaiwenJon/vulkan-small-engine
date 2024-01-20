#include <iostream>
#include "VulkanApp.h"

int main() {
    vkcpp::VulkanApp vkcppApp;

    try {
        vkcppApp.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}