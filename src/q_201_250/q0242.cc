#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 242.
 *      Valid Anagram
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given two strings ‘s’ and ‘t’ , return ‘true’ “if” ‘t’ “is an anagram
 *   of” ‘s’ “, and” ‘false’ “otherwise” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ s.length, t.length ≤ 5 × 10⁴’
 *   • ‘s’ and ‘t’ consist of lowercase English letters.
 *
 */

struct q242 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    bool isAnagram(string s, string t) {
      vector<int> cnt(26, 0);
      for (auto c : s) {
        ++cnt[c - 'a'];
      }
      for (auto c : t) {
        --cnt[c - 'a'];
      }

      for (auto c : cnt) {
        if (c != 0) {
          return false;
        }
      }

      return true;
    }
  };

  class Solution *solution;
};

TEST_F(q242, sample_input01) {
  solution = new Solution();
  string s = "anagram";
  string t = "nagaram";
  bool exp = true;
  EXPECT_EQ(solution->isAnagram(s, t), exp);
  delete solution;
}

TEST_F(q242, sample_input02) {
  solution = new Solution();
  string s = "rat";
  string t = "car";
  bool exp = false;
  EXPECT_EQ(solution->isAnagram(s, t), exp);
  delete solution;
}