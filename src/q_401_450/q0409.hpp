
#ifndef LEETCODE_Q409_H__
#define LEETCODE_Q409_H__
#include <iostream>
#include <string>
#include <unordered_map>

namespace l409 {
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 409. Longest Palindrome
  * Given a string s which consists of lowercase or
  * uppercase letters, return the length of the
  * “longest palindrome“ that can be built with those
  * letters.
  * Letters are “case sensitive“ , for example, "Aa"
  * is not considered a palindrome here.
  *
  * Constraints:
  * -  1 <= s.length <= 2000 
  * -  s consists of lowercase “and/or“ uppercase Englishletters only.
  *
*/
class Solution {
 public:
  int longestPalindrome(string s) {
    unordered_map<char, int> cnt;
    for (const auto &c : s) ++cnt[c];
    int res = 0;
    int single = 0;
    for (auto it = cnt.begin(); it != cnt.end(); ++it) {
      if (it->second % 2) {
        single = 1;
        res += it->second / 2 * 2;
      } else {
        res += it->second;
      }
    }
    return res + single;
  }
};
}  // namespace l409
#endif