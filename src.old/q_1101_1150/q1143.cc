#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 1143.
 *       Longest Common Subsequence
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given two strings ‘text1’ and ‘text2’ , return “the length of their
 *   longest “common subsequence” . ” If there is no “common subsequence” ,
 *   return ‘0’
 *   A “subsequence” of a string is a new string generated from the
 *   original string with some characters (can be none) deleted without
 *   changing the relative order of the remaining
 *       - For example, ‘'ace'’ is a subsequence of ‘'abcde'’
 *   A “common subsequence” of two strings is a subsequence that is common
 *   to both strings.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ text1.length, text2.length ≤ 1000’
 *   • ‘text1’ and ‘text2’ consist of only lowercase English characters.
 *
 */

struct q1143 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
      int m = text1.size() + 1;
      int n = text2.size() + 1;
      vector<vector<int>> dp(m, vector<int>(n, 0));
      for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
          if (text1[i - 1] == text2[j - 1]) {
            dp[i][j] = 1 + dp[i - 1][j - 1];
          } else {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
          }
        }
      }
      return dp.back().back();
    }
  };

  class Solution *solution;
};

TEST_F(q1143, sample_input01) {
  solution = new Solution();
  string text1 = "abcde";
  string text2 = "ace";
  int exp = 3;
  EXPECT_EQ(solution->longestCommonSubsequence(text1, text2), exp);
  delete solution;
}

TEST_F(q1143, sample_input02) {
  solution = new Solution();
  string text1 = "abc";
  string text2 = "abc";
  int exp = 3;
  EXPECT_EQ(solution->longestCommonSubsequence(text1, text2), exp);
  delete solution;
}

TEST_F(q1143, sample_input03) {
  solution = new Solution();
  string text1 = "abc";
  string text2 = "def";
  int exp = 0;
  EXPECT_EQ(solution->longestCommonSubsequence(text1, text2), exp);
  delete solution;
}