#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/anyorder.hpp>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 30.
 *     Substring with Concatenation of All Words
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given a string ‘s’ and an array of strings ‘words’ of “the
 *   same length” . Returnall starting indices of substring(s) in ‘s’ that
 *   is a concatenation of each word in ‘words’ “exactly once” , “in any
 *   order” ,and “without any intervening characters”
 *   You can return the answer in “any order” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ s.length ≤ 10⁴’
 *   • ‘s’ consists of lower-case English letters.
 *   • ‘1 ≤ words.length ≤ 5000’
 *   • ‘1 ≤ words[i].length ≤ 30’
 *   • ‘words[i]’ consists of lower-case English letters.
 *
 */

struct q30 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    vector<int> findSubstring(string s, vector<string> &words) {
      vector<int> res;
      unordered_map<string, int> target;
      for (const string &w : words) ++target[w];
      int len = words.front().size();
      if (len > s.size()) return res;

      int cur = 0, start = 0;
      string str;
      unordered_map<string, int> moving;
      while (cur <= s.size() - len) {
        str = s.substr(cur, len);
        if (target.count(str)) {
          ++moving[str];
          if (moving[str] <= target[str]) {
            if (moving == target) res.push_back(start);
            else {
              cur += len;
              continue;
            }
          }
        }
        moving.clear();
        ++start;
        cur = start;
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q30, sample_input01) {
  solution = new Solution();
  string s = "barfoothefoobarman";
  vector<string> words = {"foo", "bar"};
  vector<int> exp = {0, 9};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->findSubstring(s, words), exp);
  delete solution;
}

TEST_F(q30, sample_input02) {
  solution = new Solution();
  string s = "wordgoodgoodgoodbestword";
  vector<string> words = {"word", "good", "best", "word"};
  vector<int> exp = {};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->findSubstring(s, words), exp);
  delete solution;
}

TEST_F(q30, sample_input03) {
  solution = new Solution();
  string s = "barfoofoobarthefoobarman";
  vector<string> words = {"bar", "foo", "the"};
  vector<int> exp = {6, 9, 12};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->findSubstring(s, words), exp);
  delete solution;
}