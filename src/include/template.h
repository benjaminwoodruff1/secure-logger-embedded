#ifndef TEMPLATE_H
#define TEMPLATE_H

#ifdef __cplusplus
extern "C" {
#endif

// Define the function signature for loggers 
typedef void (*LogFunc)(const char* message);

// Declare global function pointer as an 'extern' variable.
extern LogFunc log_info;

// Declarations to change states at runtime
void enable_logging();
void disable_logging();

#ifdef __cplusplus
}
#endif

#endif