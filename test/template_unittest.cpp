#include <iostream>
#include <gtest/gtest.h>
#include "template_config.h"

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
