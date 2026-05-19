# Dynamic Embedded Logger

A C++ logging subsystem for resource-constrained, real-time embedded environments. This project focuses on eliminating if/else checks from execution paths by redirecting function pointers.

---

## The Engineering Challenge

In real-time embedded systems, main execution loops process high-frequency data thousands of times per second. Traditional dynamic logging relies on global boolean toggles:

void high_frequency_loop() {
    if (logging_enabled) {
        std::cout << "Telemetry check..." << std::endl;
    }
}

Even when logging is disabled most of the time, the CPU must continuously check the logging_enabled flag. Over millions of iterations, this results in increased latency and higher power consumption.

### The Solution: Function Pointer Swapping

Move the runtime decision-making outside the execution paths. By substituting a boolean flag with a mutable global function pointer (LogFunc), the system switches behaviors on the fly:

* Disabled State (Default): The pointer targets an empty NoOp_log function. The CPU hits an immediate return block, thus zero comparisons.
* Enabled State: The pointer shifts to target the active_log function, executing the underlying I/O stream operations.

---

## Architecture & Design

The project is structured around three clean layers:

1. The Contract (template.h): Defines the exact function footprint utilizing a custom type definition:
   typedef void (*LogFunc)(const char* message);
   extern LogFunc log_info;

2. The Switchboard Logic (template.cpp): Implements the memory swap mechanics:
   void enable_logging() { log_info = active_log; }
   void disable_logging() { log_info = NoOp_log; }

3. The Clean Execution Path (main.cpp): Executes straight-line function pointer invocations without pipeline-stalling conditional guards.

---

## Testing & Validation Framework

This project utilizes Google Test (GTest) to enforce system stability and catch low-level memory degradation before firmware deployment.

* Unit Testing (test/template_unittest.cpp): Implements automated I/O stream redirection. By capturing standard output buffers into isolated std::stringstream environments, the framework programmatically asserts the precise text alignment of active_log and confirms absolute silence from NoOp_log.
* Integration Testing (test/template_test.cpp): Simulates real-world operational lifecycles under extreme conditions, including an intensive 1,000-cycle rapid pointer-swapping stress test to ensure immunity against memory leaks, stale buffers, or segmentation faults during fast runtime transitions.

---

## Building and Running

The codebase uses a localized CMake build toolchain to isolate compilation artifacts.

### Prerequisites
* GCC Compiler (g++)
* CMake (v3.10+)
* Google Test Suite Framework (libgtest-dev)

### Step-by-Step Compilation

1. Navigate to the workspace build partition:
   cd build

2. Compile the targets via CMake:
   cmake --build .

3. Execute the primary application binary:
   ./bin/template_bin

4. Execute the automated Google Test Suite:
   ./bin/template_unittest_bin

---

## Key Takeaways & Learned Skills
* Low-Level Resource Optimization: Mastered how branch prediction failure and conditional evaluations impact hardware clock cycles.
* Memory Lifecycle Management: Debugged pointer lifespans and object scopes to successfully eliminate segmentation faults.
* Stream & Buffer Manipulation: Gained advanced insights into standard library stream buffers (rdbuf) to programmatically trap console outputs during automated verification.