#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1295.
 *       Find Numbers with Even Number of Digits
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an array ‘nums’ of integers, return how many of them contain an
 *   “even number” of digits.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ nums.length ≤ 500’
 *   • ‘1 ≤ nums[i] ≤ 10⁵’
 *
 */

struct q1295 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  private:
    bool isEvenDigit(int x) {
      auto res = (int)0;
      do {
        ++res;
        x /= 10;
      } while (x != 0);
      return (res & 1) == 0;
    }

  public:
    int findNumbers(vector<int> &nums) {
      auto res = (int)0;
      for (auto x : nums) {
        if (isEvenDigit(x)) {
          ++res;
        }
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1295, sample_input01) {
  solution         = new Solution();
  vector<int> nums = {12, 345, 2, 6, 7896};
  int         exp  = 2;
  int         act  = solution->findNumbers(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1295, sample_input02) {
  solution         = new Solution();
  vector<int> nums = {555, 901, 482, 1771};
  int         exp  = 1;
  int         act  = solution->findNumbers(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}