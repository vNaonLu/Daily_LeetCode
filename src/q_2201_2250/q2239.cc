#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 2239.
 *       Find Closest Number to Zero
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an integer array ‘nums’ of size ‘n’ , return “the number with
 *   the value “closest” to ” ‘0’ “ in ” ‘nums’ . If there are multiple
 *   answers, return “the number with the “largest” value” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ n ≤ 1000’
 *   • ‘-10⁵ ≤ nums[i] ≤ 10⁵’
 *
 */

struct q2239 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    int findClosestNumber(vector<int> &nums) {
      auto res = nums.front();
      for (auto x : nums) {
        if (abs(res) > abs(x) || (abs(res) == abs(x) && x > res)) {
          res = x;
        }
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q2239, sample_input01) {
  solution         = new Solution();
  vector<int> nums = {-4, -2, 1, 4, 8};
  int         exp  = 1;
  int         act  = solution->findClosestNumber(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q2239, sample_input02) {
  solution         = new Solution();
  vector<int> nums = {2, -1, 1};
  int         exp  = 1;
  int         act  = solution->findClosestNumber(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}
