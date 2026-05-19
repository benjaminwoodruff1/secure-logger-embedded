#include "template.h"
#include <iostream>

// TODO: Define your active logging function here
// TODO: Define your zero-overhead dummy function here

// Initialize the global function pointer to point to nothing for now
LogFunc log_info = nullptr;

void enable_logging() {
    // TODO: Make log_info point to your active logging function
}

void disable_logging() {
    // TODO: Make log_info point to your zero-overhead dummy function
}