
#ifndef LEETCODE_Q698_H__
#define LEETCODE_Q698_H__
#include <iostream>
#include <numeric>
#include <vector>

namespace l698 {
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 698.
  *      Partition to K Equal Sum Subsets
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   Given an integer array ‘nums’ and an integer ‘k’ , return ‘true’ if it
  *   is possible to divide this array into ‘k’ non-empty subsets whose sums
  *   are all equal.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • ‘1 ≤ k ≤ nums.length ≤ 16’
  *   • ‘1 ≤ nums[i] ≤ 10⁴’
  *   • The frequency of each element is in the range ‘[1, 4]’ .
  *
*/

class Solution {
 private:
  vector<bool> mask;
  int target = 0;
  bool DFS(const vector<int>& nums, int k, int sum = 0, int beg = 0) {
    if (k == 0) return true;
    if (sum > target) {
      return false;
    } else if (sum == target) {
      return DFS(nums, --k);
    }

    for (int i = beg; i < nums.size(); ++i) {
      if (!mask[i]) {
        mask[i] = true;
        if (DFS(nums, k, sum + nums[i], i + 1)) {
          return true;
        }
        mask[i] = false;
      }
    }
    return false;
  }

 public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % k != 0) return false;
    target = total / k;
    sort(nums.begin(), nums.end());
    mask.resize(nums.size(), false);
    return DFS(nums, k);
  }
};
}  // namespace l698

#endif