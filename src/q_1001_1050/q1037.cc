#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1037.
 *       Valid Boomerang
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an array ‘points’ where ‘points[i] = [xᵢ, yᵢ]’ represents a
 *   point on the “X-Y” plane, return ‘true’ “if these points are a
 *   “boomerang” ”
 *   A “boomerang” is a set of three points that are “all distinct” and
 *   “not in a straight line” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘points.length = 3’
 *   • ‘points[i].length = 2’
 *   • ‘0 ≤ xᵢ, yᵢ ≤ 100’
 *
 */

struct q1037 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    bool isBoomerang(vector<vector<int>> &p) {
      return p[0][0] * (p[1][1] - p[2][1]) + p[1][0] * (p[2][1] - p[0][1]) +
                 p[2][0] * (p[0][1] - p[1][1]) !=
             0;
    }
  };

  class Solution *solution;
};

TEST_F(q1037, sample_input01) {
  solution                   = new Solution();
  vector<vector<int>> points = {
      {1, 1},
      {2, 3},
      {3, 2}
  };
  bool exp = true;
  bool act = solution->isBoomerang(points);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1037, sample_input02) {
  solution                   = new Solution();
  vector<vector<int>> points = {
      {1, 1},
      {2, 2},
      {3, 3}
  };
  bool exp = false;
  bool act = solution->isBoomerang(points);
  EXPECT_EQ(act, exp);
  delete solution;
}