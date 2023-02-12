#include <gtest/gtest.h>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 217.
 *      Contains Duplicate
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an integer array ‘nums’ , return ‘true’ if any value appears “at
 *   least twice” in the array, and return ‘false’ if every element is
 *   distinct.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ nums.length ≤ 10⁵’
 *   • ‘-10⁹ ≤ nums[i] ≤ 10⁹’
 *
 */

struct q217 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
      auto memo = unordered_set<int>();
      for (auto x : nums) {
        if (false == memo.emplace(x).second) {
          return true;
        }
      }
      return false;
    }
  };

  class Solution *solution;
};

TEST_F(q217, sample_input01) {
  solution         = new Solution();
  vector<int> nums = {1, 2, 3, 1};
  bool        exp  = true;
  bool        act  = solution->containsDuplicate(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q217, sample_input02) {
  solution         = new Solution();
  vector<int> nums = {1, 2, 3, 4};
  bool        exp  = false;
  bool        act  = solution->containsDuplicate(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q217, sample_input03) {
  solution         = new Solution();
  vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  bool        exp  = true;
  bool        act  = solution->containsDuplicate(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}