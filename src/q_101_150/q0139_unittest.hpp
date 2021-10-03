
#ifndef Q139_UNITTEST_H__
#define Q139_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0139.hpp"
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 139.
  *      Word Break
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   Given a string ‘s’ and a dictionary of strings ‘wordDict’ , return
  *   ‘true’ if ‘s’ can be segmented into a space-separated sequence of one
  *   or more dictionary words.
  *   
  *   “Note” that the same word in the dictionary may be reused multiple
  *   times in the segmentation.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • ‘1 ≤ s.length ≤ 300’
  *   • ‘1 ≤ wordDict.length ≤ 1000’
  *   • ‘1 ≤ wordDict[i].length ≤ 20’
  *   • ‘s’ and ‘wordDict[i]’ consist of only lowercase English letters.
  *   • All the strings of ‘wordDict’ are “unique” .
  *
*/

TEST(q139, sample_input01) {
  l139::Solution solver;
  string s = "leetcode";
  vector<string> wordDict = {"leet", "code"};
  bool exp = true;
  EXPECT_EQ(solver.wordBreak(s, wordDict), exp);
}

TEST(q139, sample_input02) {
  l139::Solution solver;
  string s = "applepenapple";
  vector<string> wordDict = {"apple", "pen"};
  bool exp = true;
  EXPECT_EQ(solver.wordBreak(s, wordDict), exp);
}

TEST(q139, sample_input03) {
  l139::Solution solver;
  string s = "catsandog";
  vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
  bool exp = false;
  EXPECT_EQ(solver.wordBreak(s, wordDict), exp);
}

#endif