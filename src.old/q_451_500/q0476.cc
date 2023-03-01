#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 476.
 *      Number Complement
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   The “complement” of an integer is the integer you get when you flip
 *   all the ‘0’ 's to ‘1’ 's and all the ‘1’ 's to ‘0’ 's in its binary
 *       - For example, The integer ‘5’ is ‘'101'’ in binary and its
 *   “complement” is ‘'010'’ which is the integer ‘2’
 *   Given an integer ‘num’ , return “its complement” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ num < 2³¹’
 *
 */

struct q476 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int findComplement(int num) {
      unsigned mask = ~0;
      while (mask & num) mask <<= 1;
      return ~num ^ mask;
    }
  };

  class Solution *solution;
};

TEST_F(q476, sample_input01) {
  solution = new Solution();
  int num = 5;
  int exp = 2;
  int act = solution->findComplement(num);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q476, sample_input02) {
  solution = new Solution();
  int num = 1;
  int exp = 0;
  int act = solution->findComplement(num);
  EXPECT_EQ(act, exp);
  delete solution;
}