#include <gtest/gtest.h>

#include "my_math.h"

TEST(add_1, Positive) {
    EXPECT_EQ(1, my_math::add(0, 1));
}

TEST(add_2, Positive) {
    EXPECT_EQ(-4, my_math::add(-5, 1));
}