#include <array>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1996.
 *       The Number of Weak Characters in the Game
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are playing a game that contains multiple characters, and each of
 *   the characters has “two” main properties: “attack” and “defense” . You
 *   are given a 2D integer array ‘properties’ where ‘properties[i] =
 *   [attackᵢ, defenseᵢ]’ represents the properties of the ‘iᵗʰ’ character
 *   in the
 *   A character is said to be “weak” if any other character has “both”
 *   attack and defense levels “strictly greater” than this character's
 *   attack and defense levels. More formally, a character ‘i’ is said to
 *   be “weak” if there exists another character ‘j’ where ‘attackⱼ >
 *   attackᵢ’ and ‘defenseⱼ > defenseᵢ’
 *   Return “the number of “weak” characters” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘2 ≤ properties.length ≤ 10⁵’
 *   • ‘properties[i].length = 2’
 *   • ‘1 ≤ attackᵢ, defenseᵢ ≤ 10⁵’
 *
 */

struct q1996 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    int numberOfWeakCharacters(vector<vector<int>> &properties) {
      auto memo = array<int, 100002>();
      auto res  = (int)0;
      for (auto &p : properties) {
        memo[p[0]] = max(memo[p[0]], p[1]);
      }
      for (int i = 100000; i > 0; --i) {
        memo[i - 1] = max(memo[i - 1], memo[i]);
      }
      for (auto &p : properties) {
        res += memo[p[0] + 1] > p[1];
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1996, sample_input01) {
  solution                       = new Solution();
  vector<vector<int>> properties = {
      {5, 5},
      {6, 3},
      {3, 6}
  };
  int exp = 0;
  int act = solution->numberOfWeakCharacters(properties);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1996, sample_input02) {
  solution                       = new Solution();
  vector<vector<int>> properties = {
      {2, 2},
      {3, 3}
  };
  int exp = 1;
  int act = solution->numberOfWeakCharacters(properties);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1996, sample_input03) {
  solution                       = new Solution();
  vector<vector<int>> properties = {
      { 1, 5},
      {10, 4},
      { 4, 3}
  };
  int exp = 1;
  int act = solution->numberOfWeakCharacters(properties);
  EXPECT_EQ(act, exp);
  delete solution;
}