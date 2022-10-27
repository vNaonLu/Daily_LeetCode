#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 835.
 *      Image Overlap
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given two images, ‘img1’ and ‘img2’ , represented as binary,
 *   square matrices of size ‘n x n’ . A binary matrix has only ‘0’ s and
 *   ‘1’ s as
 *   We “translate” one image however we choose by sliding all the ‘1’ bits
 *   left, right, up, and/or down any number of units. We then place it on
 *   top of the other image. We can then calculate the “overlap” by
 *   counting the number of positions that have a ‘1’ in “both”
 *   Note also that a translation does “not” include any kind of rotation.
 *   Any ‘1’ bits that are translated outside of the matrix borders are
 *   Return “the largest possible overlap” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘n = img1.length = img1[i].length’
 *   • ‘n = img2.length = img2[i].length’
 *   • ‘1 ≤ n ≤ 30’
 *   • ‘img1[i][j]’ is either ‘0’ or ‘1’ .
 *   • ‘img2[i][j]’ is either ‘0’ or ‘1’ .
 *
 */

struct q835 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  private:
    int convolute(vector<vector<int>> &m, vector<vector<int>> &kernel, int xs,
                  int ys) {
      auto res = (int)0;
      for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m.size(); ++j) {
          res += m[i][j] * kernel[i + ys][j + xs];
        }
      }
      return res;
    }

  public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2) {
      auto n   = img1.size();
      auto pad = vector<vector<int>>(3 * n - 2, vector<int>(3 * n - 2));
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          pad[i + n - 1][j + n - 1] = img2[i][j];
        }
      }

      auto res = (int)0;
      for (int i = 0; i < 2 * n - 1; ++i) {
        for (int j = 0; j < 2 * n - 1; ++j) {
          res = max(res, convolute(img1, pad, i, j));
        }
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q835, sample_input01) {
  solution                 = new Solution();
  vector<vector<int>> img1 = {
      {1, 1, 0},
      {0, 1, 0},
      {0, 1, 0}
  };
  vector<vector<int>> img2 = {
      {0, 0, 0},
      {0, 1, 1},
      {0, 0, 1}
  };
  int exp = 3;
  int act = solution->largestOverlap(img1, img2);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q835, sample_input02) {
  solution                 = new Solution();
  vector<vector<int>> img1 = {{1}};
  vector<vector<int>> img2 = {{1}};
  int                 exp  = 1;
  int                 act  = solution->largestOverlap(img1, img2);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q835, sample_input03) {
  solution                 = new Solution();
  vector<vector<int>> img1 = {{0}};
  vector<vector<int>> img2 = {{0}};
  int                 exp  = 0;
  int                 act  = solution->largestOverlap(img1, img2);
  EXPECT_EQ(act, exp);
  delete solution;
}