
#ifndef Q714_UNITTEST_H__
#define Q714_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0714.hpp"
using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 714.
 *      Best Time to Buy and Sell Stock with Transaction Fee
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given an array ‘prices’ where ‘prices[i]’ is the price of a
 *   given stock on the ‘iᵗʰ’ day, and an integer ‘fee’ representing a
 *   transaction
 *   Find the maximum profit you can achieve. You may complete as many
 *   transactions as you like, but you need to pay the transaction fee for
 *   each
 *    “Note:” You may not engage in multiple transactions simultaneously
 *   (i.e., you must sell the stock before you buy again).
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ prices.length ≤ 5 × 10⁴’
 *   • ‘1 ≤ prices[i] < 5 × 10⁴’
 *   • ‘0 ≤ fee < 5 × 10⁴’
 *
 */

TEST(q714, sample_input01) {
  l714::Solution solver;
  vector<int> prices = {1, 3, 2, 8, 4, 9};
  int fee = 2;
  int exp = 8;
  EXPECT_EQ(solver.maxProfit(prices, fee), exp);
}

TEST(q714, sample_input02) {
  l714::Solution solver;
  vector<int> prices = {1, 3, 7, 5, 10, 3};
  int fee = 3;
  int exp = 6;
  EXPECT_EQ(solver.maxProfit(prices, fee), exp);
}

#endif