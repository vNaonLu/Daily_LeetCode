#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 739.
 *      Daily Temperatures
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an array of integers ‘temperatures’ represents the daily
 *   temperatures, return “an array” ‘answer’ “such that” ‘answer[i]’ “is
 *   the number of days you have to wait after the” ‘iᵗʰ’ “day to get a
 *   warmer temperature” . If there is no future day for which this is
 *   possible, keep ‘answer[i] = 0’ instead.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤temperatures.length ≤ 10⁵’
 *   • ‘30 ≤temperatures[i] ≤ 100’
 *
 */

struct q739 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      vector<int> res(temperatures.size(), 0);
      stack<int> stack;
      int wait = 1;
      for (int i = 0; i < temperatures.size(); ++i) {
        int cur = temperatures[i];
        while (!stack.empty() &&
               temperatures[stack.top()] < cur) {
          res[stack.top()] = i - stack.top();
          stack.pop();
        }
        stack.push(i);
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q739, sample_input01) {
  solution = new Solution();
  vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
  vector<int> exp = {1, 1, 4, 2, 1, 1, 0, 0};
  EXPECT_EQ(solution->dailyTemperatures(temperatures), exp);
  delete solution;
}

TEST_F(q739, sample_input02) {
  solution = new Solution();
  vector<int> temperatures = {30, 40, 50, 60};
  vector<int> exp = {1, 1, 1, 0};
  EXPECT_EQ(solution->dailyTemperatures(temperatures), exp);
  delete solution;
}

TEST_F(q739, sample_input03) {
  solution = new Solution();
  vector<int> temperatures = {30, 60, 90};
  vector<int> exp = {1, 1, 0};
  EXPECT_EQ(solution->dailyTemperatures(temperatures), exp);
  delete solution;
}