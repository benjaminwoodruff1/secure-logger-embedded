// template_test.cpp
// UT suite for example class. For demonstration only

#include <gtest/gtest.h>
#include <iostream>
#include "template.h"
#include "template.hpp"
#include "template_config.h"

// Testing class. See GTest documentation for more info
class ExampleTest : public ::testing::Test {
protected:
    ExampleTest() {}

    ~ExampleTest() override {}

    void SetUp() override {}

    void TearDown() override {}

    // Instance of example class "Template" to test
    Template uut_cpp;

    // Instance of example C struct "template_t" to test
    template_t uut_c;
};

// Test that both members of Example instance can be set accurately
TEST_F(ExampleTest, CppMemberSetTest) {
    uut_cpp.a = 2;
    uut_cpp.b = 35;
    ASSERT_EQ(uut_cpp.a, 2);
    ASSERT_EQ(uut_cpp.b, 35);
}

// Test correctness of sum() for uut_cpp, following execution of MemberSetTest
TEST_F(ExampleTest, CppSumTest) {
    ASSERT_EQ(uut_cpp.sum(), 37);
}

// Another test for the correctness of sum() for uut_cpp. Just an example
TEST_F(ExampleTest, CppSumTest2) {
    uut_cpp.a = 333;
    uut_cpp.b = -333;
    ASSERT_EQ(uut_cpp.sum(), 0);
}

// Test correctness of divide() for uut_cpp
// Note that this doesn't handle division by zero!
TEST_F(ExampleTest, CppDivideTest) {
    uut_cpp.a = 4;
    uut_cpp.b = 2;
    ASSERT_EQ(uut_cpp.divide(), 2);
}

// Test that both members of Example instance can be set accurately
TEST_F(ExampleTest, CMemberSetTest) {
    uut_c.a = 2;
    uut_c.b = 35;
    ASSERT_EQ(uut_c.a, 2);
    ASSERT_EQ(uut_c.b, 35);
}

// Test correctness of sum() for uut_cpp, following execution of MemberSetTest
TEST_F(ExampleTest, CSumTest) {
    ASSERT_EQ(template_sum(uut_c), 37);
}

// Another test for the correctness of sum() for uut_cpp. Just an example
TEST_F(ExampleTest, CSumTest2) {
    uut_c.a = 333;
    uut_c.b = -333;
    ASSERT_EQ(template_sum(uut_c), 0);
}

// Test correctness of divide() for uut_cpp
// Note that this doesn't handle division by zero!
TEST_F(ExampleTest, CDivideTest) {
    uut_c.a = 4;
    uut_c.b = 2;
    ASSERT_EQ(template_divide(uut_c), 2);
}
