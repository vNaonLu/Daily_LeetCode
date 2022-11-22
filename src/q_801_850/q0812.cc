#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 812.
 *      Largest Triangle Area
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an array of points on the “X-Y” plane ‘points’ where ‘points[i]
 *   = [xᵢ, yᵢ]’ , return “the area of the largest triangle that can be
 *   formed by any three different points” . Answers within ‘10⁻⁵’ of the
 *   actual answer will be accepted.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘3 ≤ points.length ≤ 50’
 *   • ‘-50 ≤ xᵢ, yᵢ ≤ 50’
 *   • All the given points are “unique” .
 *
 */

struct q812 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    double largestTriangleArea(vector<vector<int>> &points) {
      auto res = (double)0;
      for (auto &i : points)
        for (auto &j : points)
          for (auto &k : points)
            res = max(res, 0.5 * abs(i[0] * j[1] + j[0] * k[1] + k[0] * i[1] -
                                     j[0] * i[1] - k[0] * j[1] - i[0] * k[1]));
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q812, sample_input01) {
  solution                   = new Solution();
  vector<vector<int>> points = {
      {0, 0},
      {0, 1},
      {1, 0},
      {0, 2},
      {2, 0}
  };
  double exp = 2.00000;
  double act = solution->largestTriangleArea(points);
  EXPECT_DOUBLE_EQ(act, exp);
  delete solution;
}

TEST_F(q812, sample_input02) {
  solution                   = new Solution();
  vector<vector<int>> points = {
      {1, 0},
      {0, 0},
      {0, 1}
  };
  double exp = 0.50000;
  double act = solution->largestTriangleArea(points);
  EXPECT_DOUBLE_EQ(act, exp);
  delete solution;
}