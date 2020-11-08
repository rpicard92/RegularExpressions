#include "pch.h"
#include "../RegularExpressions/RegularExpressions.cpp"

TEST(TestCaseName, TestName) {
  RegularExpressions* reg = new RegularExpressions();
  EXPECT_EQ(false, reg->isMatch("aaba", "ab*a*c*a"));
  EXPECT_EQ(false, reg->isMatch("aaa", "aa"));
  EXPECT_EQ(true, reg->isMatch("aa", "a*"));
  EXPECT_EQ(true, reg->isMatch("aab", "c*a*b"));
  EXPECT_EQ(true, reg->isMatch("aaa", "ab*ac*a"));
  EXPECT_EQ(false, reg->isMatch("ab", ".*c"));
  EXPECT_EQ(false, reg->isMatch("abcd", "d*"));
  EXPECT_EQ(true, reg->isMatch("mississippi", "mis*is*ip*."));
  EXPECT_EQ(true, reg->isMatch("aa", "a*"));
}