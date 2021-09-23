
#ifndef Q119_UNITTEST_H__
#define Q119_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0119.hpp"
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 119. Pascal's Triangle II
  *
  * Given an integer rowIndex , return the
  * rowIndex^(th) ( “0-indexed“ ) row of the “Pascal';s
  * triangle“ .
  * In “Pascal';s triangle“ , each number is the sum
  * of the two numbers directly above it as shown:
  *
  * Constraints:
  * -  0 <= rowIndex <= 33 
  *  “Follow up:“ Could you optimize your algorithm to use only O(rowIndex) extra space?
  *
*/

TEST(q119, sample_input01) {
  int rowIndex = 3;
  vector<int> exp = {1, 3, 3, 1};
  l119::Solution solver;
  EXPECT_EQ(solver.getRow(rowIndex), exp);
}

TEST(q119, sample_input02) {
  int rowIndex = 0;
  vector<int> exp = {1};
  l119::Solution solver;
  EXPECT_EQ(solver.getRow(rowIndex), exp);
}

TEST(q119, sample_input03) {
  int rowIndex = 1;
  vector<int> exp = {1, 1};
  l119::Solution solver;
  EXPECT_EQ(solver.getRow(rowIndex), exp);
}

#endif