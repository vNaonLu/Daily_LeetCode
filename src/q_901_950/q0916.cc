#include <array>
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
 * 916.
 *      Word Subsets
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given two string arrays ‘words1’ and ‘words2’
 *   A string ‘b’ is a “subset” of string ‘a’ if every letter in ‘b’ occurs
 *   in ‘a’ including
 *       - For example, ‘'wrr'’ is a subset of ‘'warrior'’ but is not a
 *   subset of ‘'world'’
 *   A string ‘a’ from ‘words1’ is “universal” if for every string ‘b’ in
 *   ‘words2’ , ‘b’ is a subset of ‘a’
 *   Return an array of all the “universal” strings in ‘words1’ . You may
 *   return the answer in “any order” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ words1.length, words2.length ≤ 10⁴’
 *   • ‘1 ≤ words1[i].length, words2[i].length ≤ 10’
 *   • ‘words1[i]’ and ‘words2[i]’ consist only of lowercase English letters.
 *   • All the strings of ‘words1’ are “unique” .
 *
 */

struct q916 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  private:
    template <typename iterator>
    auto toLetters(iterator beg, iterator end) {
      auto res = array<int, 26>();
      while (beg != end) {
        ++res[*beg++ - 'a'];
      }

      return res;
    }

  public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
      auto res = vector<string>();
      auto reduced_word2_dict = unordered_map<int, int>();

      for (auto &w : words2) {
        auto w_cnt = unordered_map<char, int>();
        auto beg = w.begin();
        while (beg != w.end()) {
          auto curr = ++w_cnt[*beg];
          auto &global = reduced_word2_dict[*beg++];
          global = max(global, curr);
        }
      }

      for (auto &s : words1) {
        auto letters = toLetters(s.begin(), s.end());
        auto dict = reduced_word2_dict.begin();
        while (dict != reduced_word2_dict.end()) {
          auto curr = letters[dict->first - 'a'];
          if (curr < dict->second) {
            break;
          }
          ++dict;
        }

        if (dict == reduced_word2_dict.end()) {
          res.emplace_back(s);
        }
      }

      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q916, sample_input01) {
  solution = new Solution();
  vector<string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
  vector<string> words2 = {"e", "o"};
  vector<string> exp = {"facebook", "google", "leetcode"};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->wordSubsets(words1, words2), exp);
  delete solution;
}

TEST_F(q916, sample_input02) {
  solution = new Solution();
  vector<string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
  vector<string> words2 = {"l", "e"};
  vector<string> exp = {"apple", "google", "leetcode"};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->wordSubsets(words1, words2), exp);
  delete solution;
}