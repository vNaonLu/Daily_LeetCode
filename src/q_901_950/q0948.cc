#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/anyorder.hpp>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 948.
 *      Bag of Tokens
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You have an initial “power” of ‘power’ , an initial “score” of ‘0’ ,
 *   and a bag of ‘tokens’ where ‘tokens[i]’ is the value of the ‘iᵗʰ’
 *   token
 *   Your goal is to maximize your total “score” by potentially playing
 *   each token in one of two
 *       - If your current “power” is at least ‘tokens[i]’ , you may play
 *   the ‘iᵗʰ’ token face up, losing ‘tokens[i]’ “power” and gaining ‘1’
 *   “score”
 *       - If your current “score” is at least ‘1’ , you may play the ‘iᵗʰ’
 *   token face down, gaining ‘tokens[i]’ “power” and losing ‘1’ “score”
 *   Each token may be played “at most” once and “in any order” . You do
 *   “not” have to play all the
 *   Return “the largest possible “score” you can achieve after playing any
 *   number of tokens” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘0 ≤ tokens.length ≤ 1000’
 *   • ‘0 ≤ tokens[i],power < 10⁴’
 *
 */

struct q948 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    int bagOfTokensScore(vector<int> &tokens, int power) {
      sort(tokens.begin(), tokens.end());
      auto lo    = (int)0;
      auto hi    = (int)tokens.size() - 1;
      auto res   = (int)0;
      auto score = (int)0;
      while (lo <= hi && (power >= tokens[lo] || score > 0)) {
        while (lo <= hi && power >= tokens[lo]) {
          power -= tokens[lo++];
          ++score;
        }
        res = max(res, score);
        if (lo <= hi && score > 0) {
          power += tokens[hi--];
          --score;
        }
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q948, sample_input01) {
  solution           = new Solution();
  vector<int> tokens = {100};
  int         power  = 50;
  int         exp    = 0;
  int         act    = solution->bagOfTokensScore(tokens, power);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q948, sample_input02) {
  solution           = new Solution();
  vector<int> tokens = {100, 200};
  int         power  = 150;
  int         exp    = 1;
  int         act    = solution->bagOfTokensScore(tokens, power);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q948, sample_input03) {
  solution           = new Solution();
  vector<int> tokens = {100, 200, 300, 400};
  int         power  = 200;
  int         exp    = 2;
  int         act    = solution->bagOfTokensScore(tokens, power);
  EXPECT_EQ(act, exp);
  delete solution;
}