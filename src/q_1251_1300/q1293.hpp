
#ifndef LEETCODE_Q1293_H__
#define LEETCODE_Q1293_H__
#include <iostream>
#include <queue>
#include <vector>

namespace l1293 {
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 1414. Shortest Path in a Grid with Obstacles Elimination
  * You are given an m x n integer matrix grid where
  * each cell is either 0 (empty) or 1 (obstacle). You
  * can move up, down, left, or right from and to an
  * empty cell in “one step” .
  * Return the minimum number of “steps” to walk from
  * the upper left corner (0, 0) to the lower right
  * corner (m - 1, n - 1) given that you can eliminate
  * “at most” k obstacles . If it is not possible to
  * find such walk return -1 .
  *
  * Constraints:
  * -  m == grid.length 
  * -  n == grid[i].length 
  * -  1 <= m, n <= 40 
  * -  1 <= k <= m * n 
  * -  grid[i][j] == 0 “or” 1 
  * -  grid[0][0] == grid[m - 1][n - 1] == 0 
  *
*/
class Solution {
 private:
  vector<int> direct = {1, 0, 0, 1, -1, 0, 0, -1};

 public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int m = grid.size(),
        n = grid[0].size();

    vector<vector<int>> eliminated_map(m, vector<int>(n, numeric_limits<int>::max()));
    queue<pair<int, int>> q;
    q.push({0, 0});
    eliminated_map[0][0] = grid[0][0];

    int dist = 0;
    while (!q.empty()) {
      int level_size = q.size() + 1;
      while (--level_size) {
        auto cp = q.front();
        q.pop();
        if (cp.first == m - 1 && cp.second == n - 1)
          return dist;

        for (int i = 0; i < direct.size(); ++i) {
          int dx = cp.first + direct[i++];
          int dy = cp.second + direct[i];

          if (dx >= 0 && dx < m &&
              dy >= 0 && dy < n &&
              eliminated_map[cp.first][cp.second] + grid[dx][dy] <= k &&
              eliminated_map[cp.first][cp.second] + grid[dx][dy] < eliminated_map[dx][dy]) {
            eliminated_map[dx][dy] = eliminated_map[cp.first][cp.second] + grid[dx][dy];
            q.emplace(dx, dy);
          }
        }
      }
      ++dist;
    }

    return -1;
  }
};
}  // namespace l1293
#endif