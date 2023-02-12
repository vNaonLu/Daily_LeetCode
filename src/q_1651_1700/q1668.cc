#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1668.
 *       Maximum Repeating Substring
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   For a string ‘sequence’ , a string ‘word’ is “ ‘k’ -repeating” if
 *   ‘word’ concatenated ‘k’ times is a substring of ‘sequence’ . The
 *   ‘word’ 's “maximum ‘k’ -repeating value” is the highest value ‘k’
 *   where ‘word’ is ‘k’ -repeating in ‘sequence’ . If ‘word’ is not a
 *   substring of ‘sequence’ , ‘word’ 's maximum ‘k’ -repeating value is
 *   ‘0’
 *   Given strings ‘sequence’ and ‘word’ , return “the “maximum ‘k’
 *   -repeating value” of ‘word’ in ‘sequence’ ” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ sequence.length ≤ 100’
 *   • ‘1 ≤ word.length ≤ 100’
 *   • ‘sequence’ and ‘word’ contains only lowercase English letters.
 *
 */

struct q1668 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    int maxRepeating(string sequence, string word) {
      auto res = (int)0;
      auto temp = word;
      while (sequence.find(temp) != string::npos) {
        ++res;
        temp += word;
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1668, sample_input01) {
  solution        = new Solution();
  string sequence = "ababc";
  string word     = "ab";
  int    exp      = 2;
  int    act      = solution->maxRepeating(sequence, word);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1668, sample_input02) {
  solution        = new Solution();
  string sequence = "ababc";
  string word     = "ba";
  int    exp      = 1;
  int    act      = solution->maxRepeating(sequence, word);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1668, sample_input03) {
  solution        = new Solution();
  string sequence = "ababc";
  string word     = "ac";
  int    exp      = 0;
  int    act      = solution->maxRepeating(sequence, word);
  EXPECT_EQ(act, exp);
  delete solution;
}