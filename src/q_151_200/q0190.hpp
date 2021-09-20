
#ifndef LEETCODE_Q190_H__
#define LEETCODE_Q190_H__
#include <iostream>

namespace l190 {
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 190. Reverse Bits
  *
  * Reverse bits of a given 32 bits unsigned integer.
  * “Note:“ 
  * - Note that in some languages such as Java, there
  * is no unsigned integer type. In this case, both
  * input and output will be given as a signed integer
  * type. They should not affect your implementation,
  * as the integer';s internal binary representation
  * is the same, whether it is signed or unsigned.
  * - In Java,the compiler represents the signed
  * integers using <a
  * href="https://en.wikipedia.org/wiki/Two%27s_complement" target="_blank">2';s
  * complement notation</a>. Therefore, in “Example 2“ above,
  * the input represents the signed integer -3 and the
  * output represents the signed integer -1073741825 .
  * “Follow up” :
  * If this function is called many times, how would
  * you optimize it?
  *
  * Constraints:
  * - The input must be a “binary string“ of length 32 
  *
*/
class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; ++i) {
      res = (res << 1) + (n & 1);
      n >>= 1;
    }
    return res;
  }
};
}  // namespace l190
#endif