#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/anyorder.hpp>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 1002.
 *       Find Common Characters
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a string array ‘words’ , return “an array of all characters that
 *   show up in all strings within the ” ‘words’ “ (including duplicates)”
 *   . You may return the answer in “any order” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ words.length ≤ 100’
 *   • ‘1 ≤ words[i].length ≤ 100’
 *   • ‘words[i]’ consists of lowercase English letters.
 *
 */

struct q1002 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    vector<string> commonChars(vector<string> &words) {
      vector<unordered_map<char, int>> counts(words.size());
      for (int i = 0; i < words.size(); ++i)
        for (const auto &c : words[i])
          ++counts[i][c];
      vector<string> res;
      for (auto &m : counts.front()) {
        while (m.second--) {
          bool common = true;
          for (int i = 1; i < counts.size() && common; ++i)
            if (!counts[i].count(m.first) || counts[i][m.first]-- <= 0)
              common = false;
          if (common)
            res.emplace_back(1, m.first);
          else
            break;
        }
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1002, sample_input01) {
  solution = new Solution();
  vector<string> words = {"bella", "label", "roller"};
  vector<string> exp = {"e", "l", "l"};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->commonChars(words), exp);
  delete solution;
}

TEST_F(q1002, sample_input02) {
  solution = new Solution();
  vector<string> words = {"cool", "lock", "cook"};
  vector<string> exp = {"c", "o"};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->commonChars(words), exp);
  delete solution;
}