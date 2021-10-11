
#ifndef LEETCODE_Q10_H__
#define LEETCODE_Q10_H__
#include <iostream>
#include <string>
#include <vector>

namespace l10 {
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 10.
  *     Regular Expression Matching
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   Given an input string ‘s’ and a pattern ‘p’ , implement regular
  *   expression matching with support for ‘'.'’ and ‘'×'’.
  *   
  *   - ‘'.'’ Matches any single character.
  *   
  *   - ‘'×'’ Matches zero or more of the preceding element.
  *   
  *   The matching should cover the “entire” input string (not partial).
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • ‘1 ≤ s.length≤ 20’
  *   • ‘1 ≤ p.length≤ 30’
  *   • ‘s’ contains only lowercase English letters.
  *   • ‘p’ contains only lowercase English letters, ‘'.'’ , and ‘'×'’ .
  *   • It is guaranteed for each appearance of the character ‘'×'’ , there will be a previous valid character to match.
  *
*/

class Solution {
 public:
  bool isMatch(string s, string p) {
    int m = s.size() + 1, n = p.size() + 1;
    vector<vector<bool>> dp(m, vector<bool>(n, false));
    dp[0][0] = true;
    for (int j = 0; j < n; ++j)
      if (p[j - 1] == '*')
        dp[0][j] = dp[0][j - 2];

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
          dp[i][j] = dp[i - 1][j - 1];
        } else if (p[j - 1] == '*') {
          if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
            dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
          else
            dp[i][j] = dp[i][j - 2];
        }
      }
    }

    return dp.back().back();
  }
};
}  // namespace l10

#endif