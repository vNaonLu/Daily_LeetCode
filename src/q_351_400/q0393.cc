#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 393.
 *      UTF-8 Validation
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an integer array ‘data’ representing the data, return whether it
 *   is a valid “UTF-8”
 *   A character in “UTF8” can be from “1 to 4 bytes” long, subjected to
 *   the following
 *       1. For a “1-byte” character, the first bit is a ‘0’ , followed by
 *   its Unicode
 *       2. For an “n-bytes” character, the first ‘n’ bits are all one's,
 *   the ‘n + 1’ bit is ‘0’ , followed by ‘n - 1’ bytes with the most
 *   significant ‘2’ bits being ‘10’
 *   This is how the UTF-8 encoding would
 *    ‘   Char. number range  |        UTF-8 octet
 *         (hexadecimal)    |             
 *     
 *      0000 0000-0000 007F |
 *      0000 0080-0000 07FF | 110xxxxx
 *      0000 0800-0000 FFFF | 1110xxxx 10xxxxxx
 *      0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx’
 *    “Note: ” The input is an array of integers. Only the “least
 *   significant 8 bits” of each integer is used to store the data. This
 *   means each integer represents only 1 byte of data.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ data.length ≤ 2 × 10⁴’
 *   • ‘0 ≤ data[i] ≤ 255’
 *
 */

struct q393 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    int verifyFirst(int n) {
      constexpr static int mask = 1 << 7;
      int res = 0;
      while (n & mask) {
        ++res;
        n <<= 1;
      }
      return res;
    }
    bool verifyBelow(int n) {
      constexpr static int maskf = 1 << 7;
      constexpr static int masks = 1 << 6;
      return (n & maskf) && !(n & masks);
    }

   public:
    bool validUtf8(vector<int>& data) {
      for (int i = 0; i < data.size();) {
        int first = verifyFirst(data[i++]);
        switch (first) {
          case 4:
            if (i == data.size() || verifyBelow(data[i++]) == false) return false;
            [[fallthrough]];
          case 3:
            if (i == data.size() || verifyBelow(data[i++]) == false) return false;
            [[fallthrough]];
          case 2:
            if (i == data.size() || verifyBelow(data[i++]) == false) return false;
            [[fallthrough]];
          case 0:
            break;
          default:
            return false;
        }
      }
      return true;
    }
  };

  class Solution *solution;
};

TEST_F(q393, sample_input01) {
  solution = new Solution();
  vector<int> data = {197, 130, 1};
  bool exp = true;
  bool act = solution->validUtf8(data);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q393, sample_input02) {
  solution = new Solution();
  vector<int> data = {235, 140, 4};
  bool exp = false;
  bool act = solution->validUtf8(data);
  EXPECT_EQ(act, exp);
  delete solution;
}