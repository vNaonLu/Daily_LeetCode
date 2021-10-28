
#ifndef Q64_UNITTEST_H__
#define Q64_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0064.hpp"
using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 64.
 *     Minimum Path Sum
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a ‘m x n’  ‘grid’ filled with non-negative numbers, find a path
 *   from top left to bottom right, which minimizes the sum of all numbers
 *   along its
 *    “Note:” You can only move either down or right at any point in time.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘m = grid.length’
 *   • ‘n = grid[i].length’
 *   • ‘1 ≤ m, n ≤ 200’
 *   • ‘0 ≤ grid[i][j] ≤ 100’
 *
 */

TEST(q64, sample_input01) {
  l64::Solution solver;
  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  int exp = 7;
  EXPECT_EQ(solver.minPathSum(grid), exp);
}

TEST(q64, sample_input02) {
  l64::Solution solver;
  vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
  int exp = 12;
  EXPECT_EQ(solver.minPathSum(grid), exp);
}

#endif