#include <gtest/gtest.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

/**
 * The file is generated by LeetCodeDailyTools
 *
 * 2264.
 *       Largest 3-Same-Digit Number in String
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given a string ‘num’ representing a large integer. An integer
 *   is “good” if it meets the following
 *       - It is a “substring” of ‘num’ with length ‘3’
 *       - It consists of only one unique
 *   Return “the “maximum good ” integer as a “string” or an empty string ”
 *   ‘''’ “ if no such integer exists”
 *       - A “substring” is a contiguous sequence of characters within a
 *       - There may be “leading zeroes” in ‘num’ or a good integer.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘3 ≤ num.length ≤ 1000’
 *   • ‘num’ only consists of digits.
 *
 * see more details:
 * https://leetcode.com/problems/largest-3-same-digit-number-in-string/
 */

struct q2264 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    string largestGoodInteger(string num) {
      char           res = -1;
      map<char, int> freq;
      auto           lo = num.begin();
      auto           hi = lo;
      while (distance(lo, hi) < 3) {
        ++freq[*hi++];
      }
      if (freq.size() == 1) {
        res = freq.begin()->first;
      }
      while (hi != num.end()) {
        ++freq[*hi++];
        auto iter = freq.find(*lo++);
        if (--iter->second == 0) {
          freq.erase(iter);
        }
        if (freq.size() == 1) {
          res = max(res, freq.begin()->first);
        }
      }
      return res == -1 ? "" : string(3, res);
    }
  };

  class Solution *solution;
};

TEST_F(q2264, sample_input01) {
  solution   = new Solution();
  string num = "6 “<u>777</u>” 133339";
  string exp = "777";
  string act = solution->largestGoodInteger(num);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q2264, sample_input02) {
  solution   = new Solution();
  string num = "23 “<u>000</u>” 19";
  string exp = "000";
  string act = solution->largestGoodInteger(num);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q2264, sample_input03) {
  solution   = new Solution();
  string num = "42352338";
  string exp = "";
  string act = solution->largestGoodInteger(num);
  EXPECT_EQ(act, exp);
  delete solution;
}