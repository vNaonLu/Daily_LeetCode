
#ifndef LEETCODE_Q282_H__
#define LEETCODE_Q282_H__
#include <iostream>
#include <string>
#include <vector>

namespace l282 {
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 282. Expression Add Operators
  *
  * Given a string num that contains only digits and
  * an integer target , return all possibilities to
  * add the binary operators ';+'; , ';-'; , or ';*';
  * between the digits of num so that the resultant
  * expression evaluates to the target value .
  *
  * Constraints:
  * -  1 <= num.length <= 10 
  * -  num consists of only digits.
  * -  -2^(31) <= target <= 2^(31) - 1 
  *
*/
class Solution {
 private:
  long T;
  void helper(vector<string> &r, string &s, int beg, long prev, long res, string cur = "") {
    if (beg == s.size() && res == T) {
      r.push_back(cur);
      return;
    }

    string sbs = "";
    long number = 0;
    for (int i = beg; i < s.size(); ++i) {
      sbs += s[i];
      number = number * 10 + (s[i] - '0');

      if (sbs.size() > 1 && sbs[0] == '0') break;

      if (beg == 0) {
        helper(r, s, i + 1, number, number, sbs);
      } else {
        helper(r, s, i + 1, number, number + res, cur + "+" + sbs);
        helper(r, s, i + 1, -number, res - number, cur + "-" + sbs);
        helper(r, s, i + 1, number * prev, (prev * number) + (res - prev), cur + "*" + sbs);
      }
    }
  }

 public:
  vector<string> addOperators(string num, int target) {
    vector<string> res;
    T = target;
    helper(res, num, 0, 0, 0);
    return res;
  }
};
}  // namespace l282
#endif