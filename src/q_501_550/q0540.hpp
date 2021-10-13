
#ifndef LEETCODE_Q540_H__
#define LEETCODE_Q540_H__
#include <iostream>
#include <vector>

namespace l540 {
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 540.
  *      Single Element in a Sorted Array
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   You are given a sorted array consisting of only integers where every
  *   element appears exactly twice, except for one element which appears
  *   exactly once.
  *   
  *   Return “the single element that appears only once”.
  *   
  *   Your solution must run in ‘O(log n)’ time and ‘O(1)’ space.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • ‘1 ≤ nums.length ≤ 10⁵’
  *   • ‘0 ≤ nums[i] ≤ 10⁵’
  *
*/

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if ((mid % 2 == 0 && nums[mid] != nums[mid + 1]) ||
          (mid % 2 == 1 && nums[mid] != nums[mid - 1])) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return nums[l];
  }
};
}  // namespace l540

#endif