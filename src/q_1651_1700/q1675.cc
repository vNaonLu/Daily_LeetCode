#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1675.
 *       Minimize Deviation in Array
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given an array ‘nums’ of ‘n’ positive
 *   You can perform two types of operations on any element of the array
 *   any number of
 *       - If the element is “even” , “divide” it by ‘2’
 *           - For example, if the array is ‘[1,2,3,4]’ , then you can do
 *   this operation on the last element, and the array will be
 *   ‘[1,2,3,<u>2</u>].’
 *      
 *       - If the element is “odd” , “multiply” it by ‘2’
 *           - For example, if the array is ‘[1,2,3,4]’ , then you can do
 *   this operation on the first element, and the array will be
 *   ‘[<u>2</u>,2,3,4].’
 *      
 *   The “deviation” of the array is the “maximum difference” between any
 *   two elements in the
 *   Return “the “minimum deviation” the array can have after performing
 *   some number of operations.” 
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘n = nums.length’
 *   • ‘2 ≤ n ≤ 10^(<span style="font-size: 10.8333px;">5</span>)’
 *   • ‘1 ≤ nums[i] ≤ 10⁹’
 *
 */

struct q1675 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int minimumDeviation(vector<int> &nums) {
      int mx = numeric_limits<int>::min(),
          mn = numeric_limits<int>::max();
      for (auto &x : nums) {
        if (x % 2 != 0) {
          x *= 2;
        }
        mx = max(mx, x);
        mn = min(mn, x);
      }
      int res = mx - mn;
      priority_queue<int> pq;
      for (const auto &x : nums) pq.push(x);
      while (pq.top() % 2 == 0) {
        auto t = pq.top();
        pq.pop();
        res = min(res, t - mn);
        t /= 2;
        mn = min(mn, t);
        pq.push(t);
      }
      res = min(res, pq.top() - mn);
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1675, sample_input01) {
  solution = new Solution();
  vector<int> nums = {1, 2, 3, 4};
  int exp = 1;
  int act = solution->minimumDeviation(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1675, sample_input02) {
  solution = new Solution();
  vector<int> nums = {4, 1, 5, 20, 3};
  int exp = 3;
  int act = solution->minimumDeviation(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1675, sample_input03) {
  solution = new Solution();
  vector<int> nums = {2, 10, 8};
  int exp = 3;
  int act = solution->minimumDeviation(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}