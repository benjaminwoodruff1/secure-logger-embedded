#include "template.h"
#include <iostream>

void active_log(const char* message) {
    std::cout << "[Log]: " << message << std::endl;
}

void NoOp_log(const char* message) {
}

LogFunc log_info = NoOp_log;

void enable_logging() {
    log_info = active_log;
}

void disable_logging() {
    log_info = NoOp_log;
}