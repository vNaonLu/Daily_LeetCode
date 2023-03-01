#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 289.
 *      Game of Life
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   According to<a
 *   href="https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life"
 *   target="_blank">Wikipedia's article</a>: 'The “Game of Life” , also
 *   known simply as “Life” , is a cellular automaton devised by the
 *   British mathematician John Horton Conway in
 *   The board is made up of an ‘m x n’ grid of cells, where each cell has
 *   an initial state: “live” (represented by a ‘1’ ) or “dead”
 *   (represented by a ‘0’ ). Each cell interacts with its <a
 *   href="https://en.wikipedia.org/wiki/Moore_neighborhood"
 *   target="_blank">eight neighbors</a> (horizontal, vertical, diagonal)
 *   using the following four rules (taken from the above Wikipedia
 *       1. Any live cell with fewer than two live neighbors dies as if
 *   caused by
 *       2. Any live cell with two or three live neighbors lives on to the
 *   next
 *       3. Any live cell with more than three live neighbors dies, as if
 *   by
 *       4. Any dead cell with exactly three live neighbors becomes a live
 *   cell, as if by
 *   The next state is created by applying the above rules simultaneously
 *   to every cell in the current state, where births and deaths occur
 *   simultaneously. Given the current state of the ‘m x n’ grid ‘board’ ,
 *   return “the next state” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘m = board.length’
 *   • ‘n = board[i].length’
 *   • ‘1 ≤ m, n ≤ 25’
 *   • ‘board[i][j]’ is ‘0’ or ‘1’ .
 *   • Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
 *   • In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?
 *
 */

struct q289 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    int m, n;
    inline bool valid(int x, int y) {
      return x >= 0 && x < m && y >= 0 && y < n;
    }

    inline int count_neighbor(vector<vector<int>> &b, int x, int y) {
      int res = 0;
      res += valid(x - 1, y - 1) ? b[x - 1][y - 1] : 0;
      res += valid(    x, y - 1) ? b[    x][y - 1] : 0;
      res += valid(x + 1, y - 1) ? b[x + 1][y - 1] : 0;
      res += valid(x - 1,     y) ? b[x - 1][    y] : 0;
      res += valid(x + 1,     y) ? b[x + 1][    y] : 0;
      res += valid(x - 1, y + 1) ? b[x - 1][y + 1] : 0;
      res += valid(    x, y + 1) ? b[    x][y + 1] : 0;
      res += valid(x + 1, y + 1) ? b[x + 1][y + 1] : 0;

      return res;
    }

   public:
    void gameOfLife(vector<vector<int>> &board) {
      m = board.size();
      n = board.front().size();
      vector<vector<int>> res(m, vector<int>(n));

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          int neighbor = count_neighbor(board, i, j);
          if (board[i][j] == 1) {
            res[i][j] = neighbor >= 2 && neighbor <= 3 ? 1 : 0;
          } else {
            res[i][j] = neighbor == 3 ? 1 : 0;
          }
        }
      }

      swap(board, res);
    }
  };

  class Solution *solution;
};

TEST_F(q289, sample_input01) {
  solution = new Solution();
  vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
  vector<vector<int>> exp = {{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 0}};
  solution->gameOfLife(board);
  // Assume the first argument is answer.
  EXPECT_EQ(board, exp);
  delete solution;
}

TEST_F(q289, sample_input02) {
  solution = new Solution();
  vector<vector<int>> board = {{1, 1}, {1, 0}};
  vector<vector<int>> exp = {{1, 1}, {1, 1}};
  solution->gameOfLife(board);
  // Assume the first argument is answer.
  EXPECT_EQ(board, exp);
  delete solution;
}