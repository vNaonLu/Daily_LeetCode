
#ifndef LEETCODE_Q64_H__
#define LEETCODE_Q64_H__
#include <iostream>
#include <vector>

namespace l64 {
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

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    for (int i = m - 2; i >= 0; --i)
      grid[i][n - 1] += grid[i + 1].back();
    for (int i = n - 2; i >= 0; --i)
      grid[m - 1][i] += grid[m - 1][i + 1];
    for (int i = m - 2; i >= 0; --i) {
      for (int j = n - 2; j >= 0; --j) {
        grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
      }
    }
    return grid.front().front();
  }
};
}  // namespace l64

#endif