#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 2274.
 *       Maximum Consecutive Floors Without Special Floors
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Alice manages a company and has rented some floors of a building as
 *   office space. Alice has decided some of these floors should be
 *   “special floors” , used for relaxation
 *   You are given two integers ‘bottom’ and ‘top’ , which denote that
 *   Alice has rented all the floors from ‘bottom’ to ‘top’ ( “inclusive”
 *   ). You are also given the integer array ‘special’ , where ‘special[i]’
 *   denotes a special floor that Alice has designated for
 *   Return “the “maximum” number of consecutive floors without a special
 *   floor” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ special.length ≤ 10⁵’
 *   • ‘1 ≤ bottom ≤ special[i] ≤ top ≤ 10⁹’
 *   • All the values of ‘special’ are “unique” .
 *
 */

struct q2274 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    int maxConsecutive(int bottom, int top, vector<int> &special) {
      sort(special.begin(), special.end());
      int res = 0;
      res = max(res, special.front() - bottom);
      res = max(res, top - special.back());
      for (int i = 1; i < special.size(); ++i) {
        res = max(special[i] - special[i - 1] - 1, res);
      }

      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q2274, sample_input01) {
  solution = new Solution();
  int bottom = 2;
  int top = 9;
  vector<int> special = {4, 6};
  int exp = 3;
  int act = solution->maxConsecutive(bottom, top, special);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q2274, sample_input02) {
  solution = new Solution();
  int bottom = 6;
  int top = 8;
  vector<int> special = {7, 6, 8};
  int exp = 0;
  int act = solution->maxConsecutive(bottom, top, special);
  EXPECT_EQ(act, exp);
  delete solution;
}