
#ifndef LEETCODE_Q714_H__
#define LEETCODE_Q714_H__
#include <iostream>
#include <vector>

namespace l714 {
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

class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    int res = 0,
        hold = -prices[0];
    for (int i = 1; i<prices.size(); ++i){
      res = max(res, hold + prices[i] - fee);
      hold = max(hold, res - prices[i]);
    }
    return res;
  }
};
}  // namespace l714

#endif