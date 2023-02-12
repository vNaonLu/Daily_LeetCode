#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 859.
 *      Buddy Strings
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given two strings ‘s’ and ‘goal’ , return ‘true’ “ if you can swap two
 *   letters in ” ‘s’ “ so the result is equal to ” ‘goal’ “, otherwise,
 *   return ” ‘false’ “.”
 *   Swapping letters is defined as taking two indices ‘i’ and ‘j’
 *   (0-indexed) such that ‘i ≠ j’ and swapping the characters at ‘s[i]’
 *   and ‘s[j]’
 *       - For example, swapping at indices ‘0’ and ‘2’ in ‘'abcd'’ results
 *   in ‘'cbad'’ .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ s.length, goal.length ≤ 2 × 10⁴’
 *   • ‘s’ and ‘goal’ consist of lowercase letters.
 *
 */

struct q859 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    bool buddyStrings(string s, string goal) {
      if (s.size() != goal.size()) {
        return false;
      }
      auto cnt1 = vector<int>(26, 0);
      auto cnt2 = vector<int>(26, 0);
      auto diff = (int)0;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] != goal[i]) {
          ++diff;
        }
        ++cnt1[s[i] - 'a'];
        ++cnt2[goal[i] - 'a'];
      }

      auto all_unique = true;
      for (int i = 0; i < cnt1.size(); ++i) {
        if (cnt1[i] != cnt2[i]) {
          return false;
        }
        if (cnt1[i] > 1) {
          all_unique = false;
        }
      }

      return diff == 2 || (diff == 0 && !all_unique);
    }
  };

  class Solution *solution;
};

TEST_F(q859, sample_input01) {
  solution    = new Solution();
  string s    = "ab";
  string goal = "ba";
  bool   exp  = true;
  bool   act  = solution->buddyStrings(s, goal);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q859, sample_input02) {
  solution    = new Solution();
  string s    = "ab";
  string goal = "ab";
  bool   exp  = false;
  bool   act  = solution->buddyStrings(s, goal);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q859, sample_input03) {
  solution    = new Solution();
  string s    = "aa";
  string goal = "aa";
  bool   exp  = true;
  bool   act  = solution->buddyStrings(s, goal);
  EXPECT_EQ(act, exp);
  delete solution;
}