#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/anyorder.hpp>
#include <string>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 438.
 *      Find All Anagrams in a String
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given two strings ‘s’ and ‘p’ , return “an array of all the start
 *   indices of ” ‘p’ “'s anagrams in ” ‘s’ . You may return the answer in
 *   “any order”
 *   An “Anagram” is a word or phrase formed by rearranging the letters of
 *   a different word or phrase, typically using all the original letters
 *   exactly once.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ s.length, p.length ≤ 3 × 10⁴’
 *   • ‘s’ and ‘p’ consist of lowercase English letters.
 *
 */

struct q438 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
      auto res = vector<int>();
      auto cnt = vector<int>(26, 0);
      auto n   = (int)s.size();
      auto m   = (int)p.size();
      if (m <= n) {
        for (auto c : p) {
          ++cnt[c - 'a'];
        }

        auto lo = 0;
        auto hi = 0;
        auto tg = m;
        while (hi < m) {
          if (cnt[s[hi++] - 'a']-- > 0) {
            --tg;
          }
        }
        if (tg == 0) {
          res.emplace_back(lo);
        }

        while (hi < n) {
          if (cnt[s[lo++] - 'a']++ >= 0) {
            ++tg;
          }
          if (cnt[s[hi++] - 'a']-- > 0) {
            --tg;
          }
          if (tg == 0) {
            res.emplace_back(lo);
          }
        }
      }
      return res;
    }
  };
  class Solution *solution;
};

TEST_F(q438, sample_input01) {
  solution        = new Solution();
  string      s   = "cbaebabacd";
  string      p   = "abc";
  vector<int> exp = {0, 6};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->findAnagrams(s, p), exp);
  delete solution;
}

TEST_F(q438, sample_input02) {
  solution        = new Solution();
  string      s   = "abab";
  string      p   = "ab";
  vector<int> exp = {0, 1, 2};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->findAnagrams(s, p), exp);
  delete solution;
}