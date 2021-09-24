
#ifndef Q560_UNITTEST_H__
#define Q560_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0560.hpp"
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 560. Subarray Sum Equals K
  * Given an array of integers nums and an integer k
  * , return the total number of continuous subarrays
  * whose sum equals to k .
  *
  * Constraints:
  * -  1 <= nums.length <= 2 * 10^(4) 
  * -  -1000 <= nums[i] <= 1000 
  * -  -10^(7) <= k <= 10^(7) 
  *
*/

TEST(q560, sample_input01) {
  vector<int> nums = {1, 1, 1};
  int k = 2;
  int exp = 2;
  l560::Solution solver;
  EXPECT_EQ(solver.subarraySum(nums, k), exp);
}

TEST(q560, sample_input02) {
  vector<int> nums = {1, 2, 3};
  int k = 3;
  int exp = 2;
  l560::Solution solver;
  EXPECT_EQ(solver.subarraySum(nums, k), exp);
}

#endif