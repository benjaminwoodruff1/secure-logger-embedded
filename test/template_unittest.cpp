#include <iostream>
#include <gtest/gtest.h>
#include "template_config.h"
#include <iostream>
#include <sstream>
#include "template.h"

class LoggerUnitTest : public ::testing::Test {
protected:
    std::streambuf* original_cout;
    std::stringstream test_output;

    void SetUp() override {
        original_cout = std::cout.rdbuf(test_output.rdbuf());
        disable_logging();
    }

    void TearDown() override {
        std::cout.rdbuf(original_cout);
    }
};

TEST_F(LoggerUnitTest, DefaultSateIsSilent) {
    log_info("Should be silent");
    EXPECT_EQ(test_output.str(), "");
}

TEST_F(LoggerUnitTest, EnableLoggingOutputsMessages) {
    enable_logging();
    log_info("Testing Enable");
    EXPECT_EQ(test_output.str(), "[Log]: Testing Enable\n");
}

TEST_F(LoggerUnitTest, DisableLoggingReturnsToSilent) {
    enable_logging();
    disable_logging();
    log_info("This should be silent");
    EXPECT_EQ(test_output.str(), "");
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
