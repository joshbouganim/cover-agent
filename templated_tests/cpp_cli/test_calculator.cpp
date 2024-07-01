#include "calculator.hpp"
#include <gtest/gtest.h>

TEST(CalculatorTest, HandlesAddition) {
    EXPECT_DOUBLE_EQ(calculate(1, 1, "--add"), 2);
}

TEST(CalculatorTest, HandlesDivision) {
    EXPECT_THROW(calculate(1, 0, "--divide"), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
