#include "pch.h"
#include "../RegularExpressions/RegularExpressions.h"

TEST(TestCaseName, TestName) {
    RegularExpressions* reg = new RegularExpressions();
    EXPECT_EQ(false, reg->isMatch("aaba", "ab*a*c*a"));
    EXPECT_EQ(false, reg->isMatch("aaa", "aa"));
    EXPECT_EQ(true, reg->isMatch("aa", "a*"));
    EXPECT_EQ(true, reg->isMatch("aab", "c*a*b"));
}