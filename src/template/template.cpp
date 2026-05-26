#include "template.h"
#include <iostream>

extern "C" {
    bool log_info = false;

    void enable_logging() {
    log_info = true;
    }

    void disable_logging() {
        log_info = false;
    }
}