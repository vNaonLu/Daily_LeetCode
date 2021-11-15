
#ifndef LEETCODE_Q368_H__
#define LEETCODE_Q368_H__
#include <algorithm>
#include <iostream>
#include <vector>

namespace l368 {
using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 368.
 *      Largest Divisible Subset
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a set of “distinct” positive integers ‘nums’ , return the
 *   largest subset ‘answer’ such that every pair ‘(answer[i], answer[j])’
 *   of elements in this subset
 *       -  ‘answer[i] % answer[j] = 0’ ,
 *       -  ‘answer[j] % answer[i] = 0’
 *   If there are multiple solutions, return any of them.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ nums.length ≤ 1000’
 *   • ‘1 ≤ nums[i] ≤ 2 × 10⁹’
 *   • All the integers in ‘nums’ are “unique” .
 *
 */

class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> list(n, 1);
    vector<int> prev_idx(n, -1);
    int max = 0, index = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (list[j] + 1 > list[i] && nums[i] % nums[j] == 0) {
          list[i] = list[j] + 1;
          prev_idx[i] = j;
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      if (list[i] > max) {
        max = list[i];
        index = i;
      }
    }

    vector<int> res;
    while (index >= 0) {
      res.emplace_back(nums[index]);
      index = prev_idx[index];
    }
    return res;
  }
};
}  // namespace l368

#endif