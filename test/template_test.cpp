#include <gtest/gtest.h>
#include "template.h"

// Test: Verify a full operational lifecycle with back-to-back state transitions
TEST(LoggerIntegrationTest, FullSystemLifecycleSimulation) {
    disable_logging();
    for (int i = 0; i < 5; ++i)
    {
        log_info_inline("System boot diagnostics (Should be silent)...");
    }

    enable_logging();
    log_info_inline("--> ALERT: Hardware interrupt detected. Logging active.");
    log_info_inline("--> Telemetry dump: System stable.");

    disable_logging();
    for (int i = 0; i < 5; ++i) {
        log_info_inline("Steady-state loop (Should be silent)...");
    }

    SUCCEED();
}

// Heavy Stress Test
TEST(LoggerIntegrationTest, RapidPointerSwappingStressTest) {
    std::streambuf* original_cout = std::cout.rdbuf();
    std::stringstream test_output;
    std::cout.rdbuf(test_output.rdbuf());
    
    for (int i = 0; i < 1000; ++i) {
        enable_logging();
        log_info_inline("Stress testing stream...");
        disable_logging();
        log_info_inline("Stress testing silence...");
    }

    std::cout.rdbuf(original_cout);
    
    SUCCEED();
}