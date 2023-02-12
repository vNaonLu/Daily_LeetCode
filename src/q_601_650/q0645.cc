#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 645.
 *      Set Mismatch
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You have a set of integers ‘s’ , which originally contains all the
 *   numbers from ‘1’ to ‘n’ . Unfortunately, due to some error, one of the
 *   numbers in ‘s’ got duplicated to another number in the set, which
 *   results in “repetition of one” number and “loss of another”
 *   You are given an integer array ‘nums’ representing the data status of
 *   this set after the
 *   Find the number that occurs twice and the number that is missing and
 *   return “them in the form of an array” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘2 ≤ nums.length ≤ 10⁴’
 *   • ‘1 ≤ nums[i] ≤ 10⁴’
 *
 */

struct q645 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    vector<int> findErrorNums(vector<int> &nums) {
      auto dup     = (int)-1;
      auto missing = (int)1;
      for (auto x : nums) {
        if (nums[abs(x) - 1] < 0) {
          dup = abs(x);
        } else {
          nums[abs(x) - 1] *= -1;
        }
      }
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) {
          missing = i + 1;
        }
      }
      return vector<int>{dup, missing};
    }
  };

  class Solution *solution;
};

TEST_F(q645, sample_input01) {
  solution         = new Solution();
  vector<int> nums = {1, 2, 2, 4};
  vector<int> exp  = {2, 3};
  vector<int> act  = solution->findErrorNums(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q645, sample_input02) {
  solution         = new Solution();
  vector<int> nums = {1, 1};
  vector<int> exp  = {1, 2};
  vector<int> act  = solution->findErrorNums(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}