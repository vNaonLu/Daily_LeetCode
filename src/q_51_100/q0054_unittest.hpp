
#ifndef Q54_UNITTEST_H__
#define Q54_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0054.hpp"
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 54. Spiral Matrix
  *
  * Given an m x n matrix , return all elements of
  * the matrix in spiral order .
  *
  * Constraints:
  * -  m == matrix.length 
  * -  n == matrix[i].length 
  * -  1 <= m, n <= 10 
  * -  -100 <= matrix[i][j] <= 100 
  *
*/

TEST(q54, sample_input01) {
  vector<vector<int>> matrix = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};
  vector<int> exp = {1, 2, 3, 6, 9, 8, 7, 4, 5};
  l54::Solution solver;
  EXPECT_EQ(solver.spiralOrder(matrix), exp);
}

TEST(q54, sample_input02) {
  vector<vector<int>> matrix = {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12}};
  vector<int> exp = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
  l54::Solution solver;
  EXPECT_EQ(solver.spiralOrder(matrix), exp);
}

TEST(q54, input01) {
  vector<vector<int>> matrix = {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15, 16}};
  vector<int> exp = {1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10};
  l54::Solution solver;
  EXPECT_EQ(solver.spiralOrder(matrix), exp);
}

#endif