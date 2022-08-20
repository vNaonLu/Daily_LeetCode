#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/anyorder.hpp>
#include <string>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 401.
 *      Binary Watch
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   A binary watch has 4 LEDs on the top to represent the hours (0-11),
 *   and 6 LEDs on the bottom to representthe minutes (0-59). Each LED
 *   represents a zero or one, with the least significant bit on the
 *       - For example, the below binary watch reads ‘'4:51'’
 *   Given an integer ‘turnedOn’ which represents the number of LEDs that
 *   are currently on (ignoring the PM), return “all possible times the
 *   watch could represent” . You may return the answer in “any order”
 *   The hour must not contain a leading
 *       - For example, ‘'01:00'’ is not valid. It should be ‘'1:00'’
 *   The minute must be consist of two digits and may contain a leading
 *       - For example, ‘'10:2'’ is not valid. It should be ‘'10:02'’ .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘0 ≤ turnedOn ≤ 10’
 *
 */

struct q401 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  private:
    void bt(string &s, int start, int num, vector<string> &res) {
      int hour = bitset<4>(s.substr(6, 4)).to_ulong();
      int minute = bitset<6>(s.substr(0, 6)).to_ulong();
      if (hour > 11 || minute > 59) {
        return;
      }

      if (num == 0) {
        res.emplace_back(to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute));
        return;
      }

      if (start == s.size()) {
        return;
      }

      for (int i = start; i < s.size(); ++i) {
        s[i] = '1';
        bt(s, i + 1, num - 1, res);
        s[i] = '0';
      }
    }

  public:
    vector<string> readBinaryWatch(int turnedOn) {
      auto res = vector<string>();
      auto s = string("0000000000");
      bt(s, 0, turnedOn, res);

      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q401, sample_input01) {
  solution = new Solution();
  int turnedOn = 1;
  vector<string> exp = {"0:01", "0:02", "0:04", "0:08", "0:16", "0:32", "1:00", "2:00", "4:00", "8:00"};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->readBinaryWatch(turnedOn), exp);
  delete solution;
}

TEST_F(q401, sample_input02) {
  solution = new Solution();
  int turnedOn = 9;
  vector<string> exp = {};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->readBinaryWatch(turnedOn), exp);
  delete solution;
}