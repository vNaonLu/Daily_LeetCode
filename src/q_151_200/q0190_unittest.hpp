
#ifndef Q190_UNITTEST_H__
#define Q190_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0190.hpp"
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

TEST(q190, sample_input01) {
  uint32_t n = 0b00000010100101000001111010011100;
  uint32_t exp = 0b00111001011110000010100101000000;
  l190::Solution solver;
  EXPECT_EQ(solver.reverseBits(n), exp);
}

TEST(q190, sample_input02) {
  uint32_t n = 0b11111111111111111111111111111101;
  uint32_t exp = 0b10111111111111111111111111111111;
  l190::Solution solver;
  EXPECT_EQ(solver.reverseBits(n), exp);
}

#endif