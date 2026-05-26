#include <stdio.h>
#include <cstring>
#include <stdbool.h>
#include <iostream>
#include "template.h"
#include "template_config.h"

void high_frequency_loop() {
    for (int i = 0; i < 3; ++i) {
        log_info_inline("Telemetry check...");
    }
}

int main(int argc, char** argv) {
    printf("Hello, world!\n");
    printf("Version: %d.%d.%d\n", TEMPLATE_VERSION_MAJOR, TEMPLATE_VERSION_MINOR, TEMPLATE_VERSION_PATCH);
    
    printf("--- Project ---\n");

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
