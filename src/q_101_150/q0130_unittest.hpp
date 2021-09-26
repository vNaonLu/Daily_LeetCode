
#ifndef Q130_UNITTEST_H__
#define Q130_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0130.hpp"
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 130. Surrounded Regions
  * Given an m x n matrix board containing ';X'; and
  * ';O'; , capture all regions that are
  * 4-directionallysurrounded by ';X'; .
  * A region is “captured” by flipping all ';O'; s
  * into ';X'; s in that surrounded region.
  *
  * Constraints:
  * -  m == board.length 
  * -  n == board[i].length 
  * -  1 <= m, n <= 200 
  * -  board[i][j] is ';X'; or ';O'; .
  *
*/

TEST(q130, sample_input01) {
  l130::Solution solver;
  vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                {'X', 'O', 'O', 'X'},
                                {'X', 'X', 'O', 'X'},
                                {'X', 'O', 'X', 'X'}};
  vector<vector<char>> exp = {{'X', 'X', 'X', 'X'},
                              {'X', 'X', 'X', 'X'},
                              {'X', 'X', 'X', 'X'},
                              {'X', 'O', 'X', 'X'}};
  solver.solve(board);
  EXPECT_EQ(board, exp);
}

#endif