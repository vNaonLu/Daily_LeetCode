#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1266.
 *       Minimum Time Visiting All Points
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   On a 2D plane, there are ‘n’ points with integer coordinates
 *   ‘points[i] = [xᵢ, yᵢ]’ . Return “the “minimum time” in seconds to
 *   visit all the points in the order given by ” ‘points’
 *   You can move according to these
 *       - In ‘1’ second, you can
 *           - move vertically by
 *           - move horizontally by one unit,
 *           - move diagonally ‘sqrt(2)’ units (in other words, move one
 *   unit vertically then one unit horizontally in ‘1’
 *
 *       - You have to visit the points in the same order as they appear in
 *   the
 *       - You are allowed to pass through points that appear later in the
 *   order, but these do not count as visits.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘points.length = n’
 *   • ‘1 ≤ n≤ 100’
 *   • ‘points[i].length = 2’
 *   • ‘-1000≤ points[i][0], points[i][1]≤ 1000’
 *
 */

struct q1266 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points) {
      auto res = 0;

      for (auto it = points.begin() + 1; it != points.end(); ++it) {
        res += max(abs((*(it - 1))[0] - (*it)[0]), abs((*(it - 1))[1] - (*it)[1]));
      }

      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1266, sample_input01) {
  solution = new Solution();
  vector<vector<int>> points = {{1, 1}, {3, 4}, {-1, 0}};
  int exp = 7;
  int act = solution->minTimeToVisitAllPoints(points);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1266, sample_input02) {
  solution = new Solution();
  vector<vector<int>> points = {{3, 2}, {-2, 2}};
  int exp = 5;
  int act = solution->minTimeToVisitAllPoints(points);
  EXPECT_EQ(act, exp);
  delete solution;
}