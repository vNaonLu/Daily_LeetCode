#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 48.
 *     Rotate Image
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given an ‘n x n’ 2D ‘matrix’ representing an image, rotate the
 *   image by “90” degrees
 *   You have to rotate the image <a
 *   href="https://en.wikipedia.org/wiki/In-place_algorithm"
 *   target="_blank"> “in-place” </a>, which means you have to modify the
 *   input 2D matrix directly. “DO NOT” allocate another 2D matrix and do
 *   the rotation.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘matrix.length = n’
 *   • ‘matrix[i].length = n’
 *   • ‘1 ≤ n ≤ 20’
 *   • ‘-1000 ≤ matrix[i][j] ≤ 1000’
 *
 */

struct q48 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    void rotate(vector<vector<int>> &matrix) {
      auto n   = (int)matrix.size();
      auto res = vector<vector<int>>(n, vector<int>(n));
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          res[j][n - i - 1] = matrix[i][j];
        }
      }
      matrix = move(res);
    }
  };

  class Solution *solution;
};

TEST_F(q48, sample_input01) {
  solution                   = new Solution();
  vector<vector<int>> matrix = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
  };
  vector<vector<int>> exp = {
      {7, 4, 1},
      {8, 5, 2},
      {9, 6, 3}
  };
  solution->rotate(matrix);
  // Assume the first argument is answer.
  EXPECT_EQ(matrix, exp);
  delete solution;
}

TEST_F(q48, sample_input02) {
  solution                   = new Solution();
  vector<vector<int>> matrix = {
      { 5,  1,  9, 11},
      { 2,  4,  8, 10},
      {13,  3,  6,  7},
      {15, 14, 12, 16}
  };
  vector<vector<int>> exp = {
      {15, 13,  2,  5},
      {14,  3,  4,  1},
      {12,  6,  8,  9},
      {16,  7, 10, 11}
  };
  solution->rotate(matrix);
  // Assume the first argument is answer.
  EXPECT_EQ(matrix, exp);
  delete solution;
}

TEST_F(q48, sample_input03) {
  solution                   = new Solution();
  vector<vector<int>> matrix = {{1}};
  vector<vector<int>> exp    = {{1}};
  solution->rotate(matrix);
  // Assume the first argument is answer.
  EXPECT_EQ(matrix, exp);
  delete solution;
}

TEST_F(q48, sample_input04) {
  solution                   = new Solution();
  vector<vector<int>> matrix = {
      {1, 2},
      {3, 4}
  };
  vector<vector<int>> exp = {
      {3, 1},
      {4, 2}
  };
  solution->rotate(matrix);
  // Assume the first argument is answer.
  EXPECT_EQ(matrix, exp);
  delete solution;
}