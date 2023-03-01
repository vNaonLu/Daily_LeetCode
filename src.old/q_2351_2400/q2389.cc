#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 2389.
 *       Longest Subsequence With Limited Sum
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given an integer array ‘nums’ of length ‘n’ , and an integer
 *   array ‘queries’ of length ‘m’
 *   Return “an array ” ‘answer’ “ of length ” ‘m’ “ where ” ‘answer[i]’ “
 *   is the “maximum” size of a “subsequence” that you can take from ”
 *   ‘nums’ “ such that the “sum” of its elements is less than or equal to
 *   ” ‘queries[i]’
 *   A “subsequence” is an array that can be derived from another array by
 *   deleting some or no elements without changing the order of the
 *   remaining elements.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘n = nums.length’
 *   • ‘m = queries.length’
 *   • ‘1 ≤ n, m ≤ 1000’
 *   • ‘1 ≤ nums[i], queries[i] ≤ 10⁶’
 *
 */

struct q2389 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  private:
    vector<int> getPreSum(const vector<int> &n) {
      auto res = n;
      for (int i = 1; i < res.size(); ++i) {
        res[i] += res[i - 1];
      }
      return res;
    }

  public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
      sort(nums.begin(), nums.end());
      auto presum = getPreSum(nums);
      auto res    = vector<int>(queries.size(), 0);
      for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < nums.size(); ++j) {
          if (presum[j] <= queries[i]) {
            res[i] = j + 1;
          } else {
            break;
          }
        }
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q2389, sample_input01) {
  solution            = new Solution();
  vector<int> nums    = {4, 5, 2, 1};
  vector<int> queries = {3, 10, 21};
  vector<int> exp     = {2, 3, 4};
  vector<int> act     = solution->answerQueries(nums, queries);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q2389, sample_input02) {
  solution            = new Solution();
  vector<int> nums    = {2, 3, 4, 5};
  vector<int> queries = {1};
  vector<int> exp     = {0};
  vector<int> act     = solution->answerQueries(nums, queries);
  EXPECT_EQ(act, exp);
  delete solution;
}