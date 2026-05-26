#ifndef TEMPLATE_H
#define TEMPLATE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdbool.h>

// Define the function signature for loggers 
typedef void (*LogFunc)(const char* message);

// Declare global bool as an 'extern' variable.
extern bool log_info;

// Inline function to log messages based on state of log_info
// Being inlined, this function will elminate function call overhead when log_info is false/disabled
static inline void log_info_inline(const char* message) {
    if (log_info) {
        printf("[Log]: %s\n", message);    
    }
}

// Declarations to change states at runtime
void enable_logging();
void disable_logging();

#ifdef __cplusplus
}
#endif

#endif