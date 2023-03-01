#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/anyorder.hpp>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 90.
 *     Subsets II
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an integer array ‘nums’ that may contain duplicates, return “all
 *   possible subsets (the power set)”
 *   The solution set “must not” contain duplicate subsets. Return the
 *   solution in “any order” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ nums.length ≤ 10’
 *   • ‘-10 ≤ nums[i] ≤ 10’
 *
 */

struct q90 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<vector<int>> res(1, vector<int>());
      sort(nums.begin(), nums.end());
      int n = nums.size(), last = nums.front();
      int size = 1;
      for (int i = 0; i < n; i++) {
        if (last != nums[i]) {
          last = nums[i];
          size = res.size();
        }
        int len = res.size();
        for (int j = len - size; j < len; ++j) {
          res.push_back(res[j]);
          res.back().push_back(nums[i]);
        }
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q90, sample_input01) {
  solution = new Solution();
  vector<int> nums = {1, 2, 2};
  vector<vector<int>> exp = {{}, {1}, {1, 2}, {1, 2, 2}, {2}, {2, 2}};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->subsetsWithDup(nums), exp);
  delete solution;
}

TEST_F(q90, sample_input02) {
  solution = new Solution();
  vector<int> nums = {0};
  vector<vector<int>> exp = {{}, {0}};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->subsetsWithDup(nums), exp);
  delete solution;
}