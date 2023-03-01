#include <gtest/gtest.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 2248.
 *       Intersection of Multiple Arrays
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a 2D integer array ‘nums’ where ‘nums[i]’ is a non-empty array
 *   of “distinct” positive integers, return “the list of integers that are
 *   present in “each array” of” ‘nums’ “ sorted in “ascending order” ” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ nums.length ≤ 1000’
 *   • ‘1 ≤ sum(nums[i].length) ≤ 1000’
 *   • ‘1 ≤ nums[i][j] ≤ 1000’
 *   • All the values of ‘nums[i]’ are “unique” .
 *
 */

struct q2248 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    vector<int> intersection(vector<vector<int>> &nums) {
      map<int, int> freq;
      vector<int>   res;
      for (auto &v : nums) {
        for (auto x : v) {
          ++freq[x];
        }
      }
      for (auto [x, cnt] : freq) {
        if (cnt == nums.size()) {
          res.emplace_back(x);
        }
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q2248, sample_input01) {
  solution                 = new Solution();
  vector<vector<int>> nums = {
      {3, 1, 2, 4, 5},
      {1, 2, 3, 4},
      {3, 4, 5, 6}
  };
  vector<int> exp = {3, 4};
  vector<int> act = solution->intersection(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q2248, sample_input02) {
  solution                 = new Solution();
  vector<vector<int>> nums = {
      {1, 2, 3},
      {4, 5, 6}
  };
  vector<int> exp = {};
  vector<int> act = solution->intersection(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}