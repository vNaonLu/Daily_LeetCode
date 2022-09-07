#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 495.
 *      Teemo Attacking
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Our hero Teemo is attacking an enemy Ashe with poison attacks! When
 *   Teemo attacks Ashe, Ashe gets poisoned for a exactly ‘duration’
 *   seconds. More formally, an attack at second ‘t’ will mean Ashe is
 *   poisoned during the “inclusive” time interval ‘[t, t + duration - 1]’
 *   . If Teemo attacks again “before” the poison effect ends, the timer
 *   for it is “reset” , and the poison effect will end ‘duration’ seconds
 *   after the new
 *   You are given a “non-decreasing” integer array ‘timeSeries’ , where
 *   ‘timeSeries[i]’ denotes that Teemo attacks Ashe at second
 *   ‘timeSeries[i]’ , and an integer ‘duration’
 *   Return “the “total” number of seconds that Ashe is poisoned” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ timeSeries.length ≤ 10⁴’
 *   • ‘0 ≤ timeSeries[i], duration ≤ 10⁷’
 *   • ‘timeSeries’ is sorted in “non-decreasing” order.
 *
 */

struct q495 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration) {
      auto res = (int)0;
      for (auto it = timeSeries.begin() + 1; it != timeSeries.end(); ++it) {
        res += min(duration, *it - *(it - 1));
      }
      return res + duration;
    }
  };

  class Solution *solution;
};

TEST_F(q495, sample_input01) {
  solution               = new Solution();
  vector<int> timeSeries = {1, 4};
  int         duration   = 2;
  int         exp        = 4;
  int         act        = solution->findPoisonedDuration(timeSeries, duration);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q495, sample_input02) {
  solution               = new Solution();
  vector<int> timeSeries = {1, 2};
  int         duration   = 2;
  int         exp        = 3;
  int         act        = solution->findPoisonedDuration(timeSeries, duration);
  EXPECT_EQ(act, exp);
  delete solution;
}