#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1991.
 *       Find the Middle Index in Array
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a “0-indexed” integer array ‘nums’ , find the “leftmost”
 *   ‘middleIndex’ (i.e., the smallest amongst all the possible
 *   A ‘middleIndex’ is an index where ‘nums[0] + nums[1] + ... +
 *   nums[middleIndex-1] = nums[middleIndex+1] + nums[middleIndex+2] + ...
 *   + nums[nums.length-1]’
 *   If ‘middleIndex = 0’ , the left side sum is considered to be ‘0’ .
 *   Similarly, if ‘middleIndex = nums.length - 1’ , the right side sum is
 *   considered to be ‘0’
 *   Return “the “leftmost” ” ‘middleIndex’ “ that satisfies the condition,
 *   or ” ‘-1’ “ if there is no such index” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ nums.length ≤ 100’
 *   • ‘-1000 ≤ nums[i] ≤ 1000’
 *
 */

struct q1991 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int findMiddleIndex(vector<int>& nums) {
      vector<int> sum = nums;
      for (int i = 1; i < sum.size(); ++i) {
        sum[i] += sum[i - 1];
      }

      for (int i = 0; i < sum.size(); ++i) {
        if (i == 0) {
          if (sum.back() - sum[i] == 0) {
            return i;
          }

        } else if (i == sum.size() - 1) {
          if (sum[i - 1] == 0) {
            return i;
          }

        } else if (sum[i - 1] == sum.back() - sum[i]) {
          return i;
        }
      }

      return -1;
    }
  };

  class Solution *solution;
};

TEST_F(q1991, sample_input01) {
  solution = new Solution();
  vector<int> nums = {2, 3, -1, 8, 4};
  int exp = 3;
  int act = solution->findMiddleIndex(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1991, sample_input02) {
  solution = new Solution();
  vector<int> nums = {1, -1, 4};
  int exp = 2;
  int act = solution->findMiddleIndex(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1991, sample_input03) {
  solution = new Solution();
  vector<int> nums = {2, 5};
  int exp = -1;
  int act = solution->findMiddleIndex(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}