#include <cstdlib>
#include <cstring>
#include <iostream>
#include "template.h"
#include "template_config.h"

void high_frequency_loop() {
    for (int i = 0; i < 3; ++i) {
        log_info("Telemetry check...");
    }
}

int main(int argc, char** argv) {
    std::cout << "Hello, world!" << std::endl;
    std::cout << "Version: " << TEMPLATE_VERSION_MAJOR << "."
              << TEMPLATE_VERSION_MINOR << "." << TEMPLATE_VERSION_PATCH
              << std::endl;
    
    std::cout << "--- Project ---\n" << std::endl;

    // Test default state
    high_frequency_loop();
    // Test enabling logs
    enable_logging();
    high_frequency_loop();
    // Test disabling logs
    disable_logging();
    high_frequency_loop();

    return 0;
}
