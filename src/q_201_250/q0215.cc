#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 215.
 *      Kth Largest Element in an Array
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an integer array ‘nums’ and an integer ‘k’ , return “the” ‘kᵗʰ’
 *   “largest element in the array”
 *   Note that it is the ‘kᵗʰ’ largest element in the sorted order, not the
 *   ‘kᵗʰ’ distinct element.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ k ≤ nums.length ≤ 10⁴’
 *   • ‘-10⁴ ≤ nums[i] ≤ 10⁴’
 *
 */

struct q215 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());
      return *(nums.end() - k);
    }
  };

  class Solution *solution;
};

TEST_F(q215, sample_input01) {
  solution = new Solution();
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  int k = 2;
  int exp = 5;
  EXPECT_EQ(solution->findKthLargest(nums, k), exp);
  delete solution;
}

TEST_F(q215, sample_input02) {
  solution = new Solution();
  vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  int k = 4;
  int exp = 4;
  EXPECT_EQ(solution->findKthLargest(nums, k), exp);
  delete solution;
}