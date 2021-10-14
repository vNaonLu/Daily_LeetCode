
#ifndef LEETCODE_Q918_H__
#define LEETCODE_Q918_H__
#include <iostream>
#include <numeric>
#include <vector>

namespace l918 {
using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 918.
 *      Maximum Sum Circular Subarray
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a “circular integer array” ‘nums’ of length ‘n’ , return “the
 *   maximum possible sum of a non-empty “subarray” of ” ‘nums’
 *   A “circular array” means the end of the array connects to the
 *   beginning of the array. Formally, the next element of ‘nums[i]’ is
 *   ‘nums[(i + 1) % n]’ and the previous element of ‘nums[i]’ is ‘nums[(i
 *   - 1 + n) % n]’
 *   A “subarray” may only include each element of the fixed buffer ‘nums’
 *   at most once. Formally, for a subarray ‘nums[i], nums[i + 1], ...,
 *   nums[j]’ , there does not exist ‘i ≤ k1’ , ‘k2 ≤ j’ with ‘k1 % n = k2
 *   % n’ .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘n = nums.length’
 *   • ‘1 ≤ n ≤ 3 × 10⁴’
 *   • ‘-3 × 10⁴ ≤ nums[i] ≤ 3 × 10⁴’
 *
 */

class Solution {
 private:
  int kadane(vector<int>::iterator beg, vector<int>::iterator end, int sign) {
    if (beg == end) return 0;
    int res = *beg * sign,
        lmx = *beg * sign;
    ++beg;
    while (beg != end) {
      lmx = *(beg++) * sign + max(0, lmx);
      res = max(res, lmx);
    }
    return res;
  }

 public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return max({kadane(nums.begin(), nums.end(), 1),
                sum + kadane(nums.begin() + 1, nums.end(), -1),
                sum + kadane(nums.begin(), nums.end() - 1, -1)});
  }
};
}  // namespace l918

#endif