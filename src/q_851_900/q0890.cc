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
 * 890.
 *      Find and Replace Pattern
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a list of strings ‘words’ and a string ‘pattern’ , return “a
 *   list of” ‘words[i]’ “that match” ‘pattern’ . You may return the answer
 *   in “any order”
 *   A word matches the pattern if there exists a permutation of letters
 *   ‘p’ so that after replacing every letter ‘x’ in the pattern with
 *   ‘p(x)’ , we get the desired
 *   Recall that a permutation of letters is a bijection from letters to
 *   letters: every letter maps to another letter, and no two letters map
 *   to the same letter.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ pattern.length ≤ 20’
 *   • ‘1 ≤ words.length ≤ 50’
 *   • ‘words[i].length = pattern.length’
 *   • ‘pattern’ and ‘words[i]’ are lowercase English letters.
 *
 */

struct q890 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  private:
    template <typename iterator>
    vector<int> toPermutation(iterator beg, iterator end) {
      auto dict = unordered_map<int, int>();
      auto res = vector<int>();
      auto cnt = 0;

      while (beg != end) {
        auto find = dict.find(*beg);
        if (find == dict.end()) {
          res.emplace_back(dict[*beg] = cnt++);
        } else {
          res.emplace_back(find->second);
        }
        ++beg;
      }

      return res;
    }

  public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
      auto res = vector<string>();
      auto key = toPermutation(pattern.begin(), pattern.end());

      for (auto &s : words) {
        auto curr = toPermutation(s.begin(), s.end());

        if (curr == key) {
          res.emplace_back(s);
        }
      }

      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q890, sample_input01) {
  solution = new Solution();
  vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
  string pattern = "abb";
  vector<string> exp = {"mee", "aqq"};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->findAndReplacePattern(words, pattern), exp);
  delete solution;
}

TEST_F(q890, sample_input02) {
  solution = new Solution();
  vector<string> words = {"a", "b", "c"};
  string pattern = "a";
  vector<string> exp = {"a", "b", "c"};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->findAndReplacePattern(words, pattern), exp);
  delete solution;
}