#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 796.
 *      Rotate String
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given two strings ‘s’ and ‘goal’ , return ‘true’ “if and only if” ‘s’
 *   “can become” ‘goal’ “after some number of “shifts” on” ‘s’
 *   A “shift” on ‘s’ consists of moving the leftmost character of ‘s’ to
 *   the rightmost
 *       - For example, if ‘s = 'abcde'’ , then it will be ‘'bcdea'’ after
 *   one shift.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ s.length, goal.length ≤ 100’
 *   • ‘s’ and ‘goal’ consist of lowercase English letters.
 *
 */

struct q796 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    bool rotateString(string s, string goal) {
      return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
  };

  class Solution *solution;
};

TEST_F(q796, sample_input01) {
  solution    = new Solution();
  string s    = "abcde";
  string goal = "cdeab";
  bool   exp  = true;
  bool   act  = solution->rotateString(s, goal);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q796, sample_input02) {
  solution    = new Solution();
  string s    = "abcde";
  string goal = "abced";
  bool   exp  = false;
  bool   act  = solution->rotateString(s, goal);
  EXPECT_EQ(act, exp);
  delete solution;
}