#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1652.
 *       Defuse the Bomb
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You have a bomb to defuse, and your time is running out! Your informer
 *   will provide you with a “circular” array ‘code’ of length of ‘n’ and a
 *   key ‘k’
 *   To decrypt the code, you must replace every number. All the numbers
 *   are replaced “simultaneously”
 *       - If ‘k > 0’ , replace the ‘iᵗʰ’ number with the sum of the “next”
 *   ‘k’
 *       - If ‘k < 0’ , replace the ‘iᵗʰ’ number with the sum of the
 *   “previous” ‘k’
 *       - If ‘k = 0’ , replace the ‘iᵗʰ’ number with ‘0’
 *   As ‘code’ is circular, the next element of ‘code[n-1]’ is ‘code[0]’ ,
 *   and the previous element of ‘code[0]’ is ‘code[n-1]’
 *   Given the “circular” array ‘code’ and an integer key ‘k’ , return “the
 *   decrypted code to defuse the bomb” !
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘n = code.length’
 *   • ‘1 ≤ n≤ 100’
 *   • ‘1 ≤ code[i] ≤ 100’
 *   • ‘-(n - 1) ≤ k ≤ n - 1’
 *
 */

struct q1652 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    vector<int> decrypt(vector<int> &code, int k) {
      if (k == 0) {
        return vector<int>(code.size());
      } else {
        auto n   = code.size();
        auto res = vector<int>(n);
        if (k > 0) {
          for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
              res[i] += code[(i + j) % n];
            }
          }
        } else {
          for (int i = 0; i < n; ++i) {
            for (int j = -1; j >= k; --j) {
              res[i] += code[(i + j + n) % n];
            }
          }
        }
        return res;
      }
    }
  };

  class Solution *solution;
};

TEST_F(q1652, sample_input01) {
  solution         = new Solution();
  vector<int> code = {5, 7, 1, 4};
  int         k    = 3;
  vector<int> exp  = {12, 10, 16, 13};
  vector<int> act  = solution->decrypt(code, k);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1652, sample_input02) {
  solution         = new Solution();
  vector<int> code = {1, 2, 3, 4};
  int         k    = 0;
  vector<int> exp  = {0, 0, 0, 0};
  vector<int> act  = solution->decrypt(code, k);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1652, sample_input03) {
  solution         = new Solution();
  vector<int> code = {2, 4, 9, 3};
  int         k    = -2;
  vector<int> exp  = {12, 5, 6, 13};
  vector<int> act  = solution->decrypt(code, k);
  EXPECT_EQ(act, exp);
  delete solution;
}