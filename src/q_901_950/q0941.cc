#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 941.
 *      Valid Mountain Array
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an array of integers ‘arr’ , return “ ‘true’ if and only if it
 *   is a valid mountain array”
 *   Recall that arr is a mountain array if and only
 *       -  ‘arr.length ≥ 3’
 *       - There exists some ‘i’ with ‘0 < i < arr.length - 1’ such
 *           -  ‘arr[0] < arr[1] < ... < arr[i - 1] < arr[i] ’
 *           -  ‘arr[i] > arr[i + 1] > ... > arr[arr.length - 1]’
 *       	
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ arr.length ≤ 10⁴’
 *   • ‘0 ≤ arr[i] ≤ 10⁴’
 *
 */

struct q941 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    bool validMountainArray(vector<int>& arr) {
      if (arr.size() < 3) return false;
      auto prev = arr.begin(),
           curr = prev + 1;
      /// increasing
      while (curr != arr.end() && *curr > *prev) {
        ++prev, ++curr;
      }
      if (curr == arr.end() || prev == arr.begin()) return false;
      /// decreasing
      while (curr != arr.end() && *curr < *prev) {
        ++prev, ++curr;
      }
      return curr == arr.end();
    }
  };

  class Solution *solution;
};

TEST_F(q941, sample_input01) {
  solution = new Solution();
  vector<int> arr = {2, 1};
  bool exp = false;
  bool act = solution->validMountainArray(arr);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q941, sample_input02) {
  solution = new Solution();
  vector<int> arr = {3, 5, 5};
  bool exp = false;
  bool act = solution->validMountainArray(arr);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q941, sample_input03) {
  solution = new Solution();
  vector<int> arr = {0, 3, 2, 1};
  bool exp = true;
  bool act = solution->validMountainArray(arr);
  EXPECT_EQ(act, exp);
  delete solution;
}