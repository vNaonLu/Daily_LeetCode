
#ifndef Q120_UNITTEST_H__
#define Q120_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0120.hpp"
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 120. Triangle
  *
  * Given a triangle array, return the minimum path
  * sum from top to bottom .
  * For each step, you may move to an adjacent number
  * of the row below. More formally, if you are on
  * index i on the current row, you may move to either
  * index i or index i + 1 on the next row.
  *
  * Constraints:
  * -  1 <= triangle.length <= 200 
  * -  triangle[0].length == 1 
  * -  triangle[i].length == triangle[i - 1].length + 1 
  * -  -10^(4) <= triangle[i][j] <= 10^(4) 
  *  “Follow up:“ Could youdo this using only O(n) extra space, where n is the total number of rows in the triangle?
  *
*/

TEST(q120, sample_input01) {
  vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  int exp = 11;
  l120::Solution solver;
  EXPECT_EQ(solver.minimumTotal(triangle), exp);
}

TEST(q120, sample_input02) {
  vector<vector<int>> triangle = {{-10}};
  int exp = -10;
  l120::Solution solver;
  EXPECT_EQ(solver.minimumTotal(triangle), exp);
}

#endif