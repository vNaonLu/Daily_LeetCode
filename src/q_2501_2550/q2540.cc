#include <gtest/gtest.h>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 2540.
 *       Minimum Common Value
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given two integer arrays ‘nums1’ and ‘nums2’ , sorted in
 *   non-decreasing order, return “the “minimum integer common” to both
 *   arrays” . If there is no common integer amongst ‘nums1’ and ‘nums2’ ,
 *   return ‘-1’
 *   Note that an integer is said to be “common” to ‘nums1’ and ‘nums2’ if
 *   both arrays have “at least one” occurrence of that integer.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ nums1.length, nums2.length ≤ 10⁵’
 *   • ‘1 ≤ nums1[i], nums2[j] ≤ 10⁹’
 *   • Both ‘nums1’ and ‘nums2’ are sorted in “non-decreasing” order.
 *
 */

struct q2540 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    int getCommon(vector<int> &nums1, vector<int> &nums2) {
      unordered_set<int> memo;
      for (auto x : nums1) {
        memo.emplace(x);
      }
      for (auto x : nums2) {
        if (memo.count(x)) {
          return x;
        }
      }
      return -1;
    }
  };

  class Solution *solution;
};

TEST_F(q2540, sample_input01) {
  solution          = new Solution();
  vector<int> nums1 = {1, 2, 3};
  vector<int> nums2 = {2, 4};
  int         exp   = 2;
  int         act   = solution->getCommon(nums1, nums2);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q2540, sample_input02) {
  solution          = new Solution();
  vector<int> nums1 = {1, 2, 3, 6};
  vector<int> nums2 = {2, 3, 4, 5};
  int         exp   = 2;
  int         act   = solution->getCommon(nums1, nums2);
  EXPECT_EQ(act, exp);
  delete solution;
}
