#include <iostream>
#include <gtest/gtest.h>
#include "template_config.h"
#include <iostream>
#include <sstream>
#include "template.h"
#include <stdio.h>
#include <fstream>
#include <unistd.h>

class LoggerUnitTest : public ::testing::Test {
protected:
    void SetUp() override {
        disable_logging();
        testing::internal::CaptureStdout();
        }

    void TearDown() override {
        (void)testing::internal::GetCapturedStdout();
    }

    std::string GetCapturedOutput() {
        std::string output = testing::internal::GetCapturedStdout();
        testing::internal::CaptureStdout();
        return output;
    }
};

TEST_F(LoggerUnitTest, DefaultSateIsSilent) {
    log_info_inline("Should be silent");
    EXPECT_EQ(GetCapturedOutput(), "");
}

TEST_F(LoggerUnitTest, EnableLoggingOutputsMessages) {
    enable_logging();
    log_info_inline("Testing Enable");
    EXPECT_EQ(GetCapturedOutput(), "[Log]: Testing Enable\n");
}

TEST_F(LoggerUnitTest, DisableLoggingReturnsToSilent) {
    enable_logging();
    disable_logging();
    log_info_inline("This should be silent");
    EXPECT_EQ(GetCapturedOutput(), "");
}

int main (int argc, char** argv) {
  std::cout << "============================================================="
            << std::endl << "============== UT Suite for template (v"
            << TEMPLATE_VERSION_MAJOR << "."
            << TEMPLATE_VERSION_MINOR << "."
            << TEMPLATE_VERSION_PATCH << ") ===============" << std::endl
            << "============================================================="
            << std::endl;
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
