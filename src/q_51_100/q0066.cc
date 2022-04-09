#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 66.
 *     Plus One
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given a “large integer” represented as an integer array
 *   ‘digits’ , where each ‘digits[i]’ is the ‘iᵗʰ’ digit of the integer.
 *   The digits are ordered from most significant to least significant in
 *   left-to-right order. The large integer does not contain any leading
 *   ‘0’
 *   Increment the large integer by one and return “the resulting array of
 *   digits” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ digits.length ≤ 100’
 *   • ‘0 ≤ digits[i] ≤ 9’
 *   • ‘digits’ does not contain any leading ‘0’ 's.
 *
 */

struct q66 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
      if (digits.empty()) return vector<int>{};
      vector<int> res = digits;
      int plus = 1;
      for (int i = res.size() - 1; i >= 0 && plus != 0; i--) {
        res[i] += plus;
        plus = res[i] / 10;
        res[i] %= 10;
      }
      if (plus > 0) res.insert(res.begin(), plus);
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q66, sample_input01) {
  solution = new Solution();
  vector<int> digits = {1, 2, 3};
  vector<int> exp = {1, 2, 4};
  vector<int> act = solution->plusOne(digits);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q66, sample_input02) {
  solution = new Solution();
  vector<int> digits = {4, 3, 2, 1};
  vector<int> exp = {4, 3, 2, 2};
  vector<int> act = solution->plusOne(digits);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q66, sample_input03) {
  solution = new Solution();
  vector<int> digits = {9};
  vector<int> exp = {1, 0};
  vector<int> act = solution->plusOne(digits);
  EXPECT_EQ(act, exp);
  delete solution;
}