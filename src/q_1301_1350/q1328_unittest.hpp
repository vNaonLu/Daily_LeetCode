
#ifndef Q1328_UNITTEST_H__
#define Q1328_UNITTEST_H__
#include <gtest/gtest.h>

#include "q1328.hpp"
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 1328. Break a Palindrome
  * Given a palindromic string of lowercase English
  * letters palindrome , replace “exactly one“
  * character with any lowercase English letter so that the
  * resulting string is “not“ a palindrome and that it
  * is the “lexicographically smallest“ one possible.
  * Return the resulting string. If there is no way
  * to replace a character to make it not a palindrome,
  * return an “empty string“ . 
  * A string a is lexicographically smaller than a
  * string b (of the same length) if in the first
  * position where a and b differ, a has a character
  * strictly smaller than the corresponding character in b .
  * For example, "abcc" is lexicographically smaller
  * than "abcd" because the first position they differ
  * is at the fourth character, and ';c'; is smaller
  * than ';d'; .
  *
  * Constraints:
  * -  1 <= palindrome.length <= 1000 
  * -  palindrome consists of only lowercase English letters.
  *
*/

TEST(q1328, sample_input01) {
  string palindrome = "abccba";
  string exp = "aaccba";
  l1328::Solution solver;
  EXPECT_EQ(solver.breakPalindrome(palindrome), exp);
}

TEST(q1328, sample_input02) {
  string palindrome = "a";
  string exp = "";
  l1328::Solution solver;
  EXPECT_EQ(solver.breakPalindrome(palindrome), exp);
}

TEST(q1328, sample_input03) {
  string palindrome = "aa";
  string exp = "ab";
  l1328::Solution solver;
  EXPECT_EQ(solver.breakPalindrome(palindrome), exp);
}

TEST(q1328, sample_input04) {
  string palindrome = "aba";
  string exp = "abb";
  l1328::Solution solver;
  EXPECT_EQ(solver.breakPalindrome(palindrome), exp);
}

#endif