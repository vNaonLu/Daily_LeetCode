#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <string_view>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 899.
 *      Orderly Queue
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given a string ‘s’ and an integer ‘k’ . You can choose one of
 *   the first ‘k’ letters of ‘s’ and append it at the end of the
 *   Return “the lexicographically smallest string you could have after
 *   applying the mentioned step any number of moves” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ k ≤ s.length ≤ 1000’
 *   • ‘s’ consist of lowercase English letters.
 *
 */

struct q899 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    string orderlyQueue(string s, int k) {
      if (k == 1) {
        s.reserve(s.size() * 2);
        auto res = string_view(s);
        s += s;
        auto sv = string_view(s);
        for (int i = 0; i < res.size(); ++i) {
          res = min(res, sv.substr(i, res.size()));
        }
        return string(res);
      }
      sort(s.begin(), s.end());
      return s;
    }
  };

  class Solution *solution;
};

TEST_F(q899, sample_input01) {
  solution   = new Solution();
  string s   = "cba";
  int    k   = 1;
  string exp = "acb";
  string act = solution->orderlyQueue(s, k);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q899, sample_input02) {
  solution   = new Solution();
  string s   = "baaca";
  int    k   = 3;
  string exp = "aaabc";
  string act = solution->orderlyQueue(s, k);
  EXPECT_EQ(act, exp);
  delete solution;
}