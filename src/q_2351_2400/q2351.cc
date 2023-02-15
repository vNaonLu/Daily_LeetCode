#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 2351.
 *       First Letter to Appear Twice
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a string ‘s’ consisting of lowercase English letters, return
 *   “the first letter to appear “twice” ”
 *    “Note”
 *       - A letter ‘a’ appears twice before another letter ‘b’ if the
 *   “second” occurrence of ‘a’ is before the “second” occurrence of ‘b’
 *       -  ‘s’ will contain at least one letter that appears twice.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘2 ≤ s.length ≤ 100’
 *   • ‘s’ consists of lowercase English letters.
 *   • ‘s’ has at least one repeated letter.
 *
 * see more details: https://leetcode.com/problems/first-letter-to-appear-twice/
 */

struct q2351 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    char repeatedCharacter(string s) {
      unordered_set<char> memo;
      for (auto c : s) {
        if (!memo.emplace(c).second) {
          return c;
        }
      }
      return ' ';
    }
  };

  class Solution *solution;
};

TEST_F(q2351, sample_input01) {
  solution   = new Solution();
  string s   = "abccbaacz";
  char   exp = 'c';
  char   act = solution->repeatedCharacter(s);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q2351, sample_input02) {
  solution   = new Solution();
  string s   = "abcdd";
  char   exp = 'd';
  char   act = solution->repeatedCharacter(s);
  EXPECT_EQ(act, exp);
  delete solution;
}
