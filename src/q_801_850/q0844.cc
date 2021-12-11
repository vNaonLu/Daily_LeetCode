#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 844.
 *      Backspace String Compare
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given two strings ‘s’ and ‘t’ , return ‘true’ “if they are equal when
 *   both are typed into empty text editors” . ‘'#'’ means a backspace
 *   Note that after backspacing an empty text, the text will continue
 *   empty.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ s.length, t.length ≤ 200’
 *   • ‘s’ and ‘t’ only containlowercase letters and ‘'#'’ characters.
 *
 */

struct q844 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    bool backspaceCompare(string s, string t) {
      stack<char> ss, ts;
      for (const auto &c : s) {
        if (c == '#') {
          if (!ss.empty()) {
            ss.pop();
          }
        } else {
          ss.push(c);
        }
      }
      for (const auto &c : t) {
        if (c == '#') {
          if (!ts.empty()) {
            ts.pop();
          }
        } else {
          ts.push(c);
        }
      }
      return ts == ss;
    }
  };

  class Solution *solution;
};

TEST_F(q844, sample_input01) {
  solution = new Solution();
  string s = "ab#c";
  string t = "ad#c";
  bool exp = true;
  EXPECT_EQ(solution->backspaceCompare(s, t), exp);
  delete solution;
}

TEST_F(q844, sample_input02) {
  solution = new Solution();
  string s = "ab##";
  string t = "c#d#";
  bool exp = true;
  EXPECT_EQ(solution->backspaceCompare(s, t), exp);
  delete solution;
}

TEST_F(q844, sample_input03) {
  solution = new Solution();
  string s = "a##c";
  string t = "#a#c";
  bool exp = true;
  EXPECT_EQ(solution->backspaceCompare(s, t), exp);
  delete solution;
}

TEST_F(q844, sample_input04) {
  solution = new Solution();
  string s = "a#c";
  string t = "b";
  bool exp = false;
  EXPECT_EQ(solution->backspaceCompare(s, t), exp);
  delete solution;
}