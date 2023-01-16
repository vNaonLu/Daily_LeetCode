#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 2235.
 *       Add Two Integers
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given two integers ‘num1’ and ‘num2’ , return “the “sum” of the two
 *   integers” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘-100 ≤ num1, num2 ≤ 100’
 *
 */

struct q2235 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    int sum(int num1, int num2) { return num1 + num2; }
  };

  class Solution *solution;
};

TEST_F(q2235, sample_input01) {
  solution = new Solution();
  int num1 = 12;
  int num2 = 5;
  int exp  = 17;
  int act  = solution->sum(num1, num2);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q2235, sample_input02) {
  solution = new Solution();
  int num1 = -10;
  int num2 = 4;
  int exp  = -6;
  int act  = solution->sum(num1, num2);
  EXPECT_EQ(act, exp);
  delete solution;
}
