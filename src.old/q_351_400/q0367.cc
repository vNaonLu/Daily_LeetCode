#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 367.
 *      Valid Perfect Square
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a “positive” integer <i>num</i>, write a function which returns
 *   True if <i>num</i> is a perfect square else
 *    “Follow up:”  “Do not” use any built-in library function such as
 *   ‘sqrt’ .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ num ≤ 2^31 - 1’
 *
 */

struct q367 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    bool isPerfectSquare(int num) {
      unsigned long long l = 1, r = num;
      while (l <= r) {
        unsigned long long m = l + (r - l) / 2;
        if (m * m == num) {
          return true;
        } else if (m * m < num) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      }

      return false;
    }
  };

  class Solution *solution;
};

TEST_F(q367, sample_input01) {
  solution = new Solution();
  int num = 16;
  bool exp = true;
  bool act = solution->isPerfectSquare(num);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q367, sample_input02) {
  solution = new Solution();
  int num = 14;
  bool exp = false;
  bool act = solution->isPerfectSquare(num);
  EXPECT_EQ(act, exp);
  delete solution;
}