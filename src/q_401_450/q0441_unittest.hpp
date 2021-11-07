
#ifndef Q441_UNITTEST_H__
#define Q441_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0441.hpp"
using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 441.
 *      Arranging Coins
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You have ‘n’ coins and you want to build a staircase with these coins.
 *   The staircase consists of ‘k’ rows where the ‘iᵗʰ’ row has exactly ‘i’
 *   coins. The last row of the staircase “may be”
 *   Given the integer ‘n’ , return “the number of “complete rows” of the
 *   staircase you will build” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ n ≤ 2³¹ - 1’
 *
 */

TEST(q441, sample_input01) {
  l441::Solution solver;
  int n = 5;
  int exp = 2;
  EXPECT_EQ(solver.arrangeCoins(n), exp);
}

TEST(q441, sample_input02) {
  l441::Solution solver;
  int n = 8;
  int exp = 3;
  EXPECT_EQ(solver.arrangeCoins(n), exp);
}

#endif