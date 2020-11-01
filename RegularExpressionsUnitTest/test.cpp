#include "pch.h"
#include "../RegularExpressions/RegularExpressions.h"

TEST(TestCaseName, TestName) {
    RegularExpressions* reg = new RegularExpressions();
    EXPECT_EQ(true, reg->isMatch("aaba", "ab*a*c*a"));
}