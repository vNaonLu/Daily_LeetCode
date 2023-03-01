#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 509.
 *      Fibonacci Number
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   The “Fibonacci numbers” , commonly denoted ‘F(n)’ form a sequence,
 *   called the “Fibonacci sequence” , such that each number is the sum of
 *   the two preceding ones, starting from ‘0’ and ‘1’ . That
 *   F(0) = 0, F(1) =
 *   F(n) = F(n - 1) + F(n - 2), for n >
 *   Given ‘n’ , calculate ‘F(n)’ .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘0 ≤ n ≤ 30’
 *
 */

struct q509 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int fib(int n) {
      if (n == 0) return 0;
      if (n == 1) return 1;
      int frs = 0, scd = 1;
      for (int i = 2; i < n; ++i) {
        scd += frs;
        frs = scd - frs;
      }
      return frs + scd;
    }
  };

  class Solution *solution;
};

TEST_F(q509, sample_input01) {
  solution = new Solution();
  int n = 2;
  int exp = 1;
  EXPECT_EQ(solution->fib(n), exp);
  delete solution;
}

TEST_F(q509, sample_input02) {
  solution = new Solution();
  int n = 3;
  int exp = 2;
  EXPECT_EQ(solution->fib(n), exp);
  delete solution;
}

TEST_F(q509, sample_input03) {
  solution = new Solution();
  int n = 4;
  int exp = 3;
  EXPECT_EQ(solution->fib(n), exp);
  delete solution;
}