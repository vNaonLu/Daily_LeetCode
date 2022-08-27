#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 317.
 *      Shortest Distance from All Buildings
 *
 * To unlock the question need a premium account.
 *
 */

struct q317 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    int getSum(int a, int b) {
      while (b != 0) {
        auto carry = a & b;
        a ^= b;
        b = (uint32_t)carry << 1;
      }
      return a;
    }
  };

  class Solution *solution;
};

TEST_F(q317, sample_input01) {
  solution = new Solution();
  int  a   = 1;
  int  b   = 2;
  bool exp = 3;
  bool act = solution->getSum(a, b);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q317, sample_input02) {
  solution = new Solution();
  int  a   = 2;
  int  b   = 3;
  bool exp = 5;
  bool act = solution->getSum(a, b);
  EXPECT_EQ(act, exp);
  delete solution;
}
