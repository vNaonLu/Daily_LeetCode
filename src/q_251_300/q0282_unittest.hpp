
#ifndef Q282_UNITTEST_H__
#define Q282_UNITTEST_H__
#include <gtest/gtest.h>

#include <algorithm>

#include "q0282.hpp"
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

TEST(q282, sample_input01) {
  string num = "123";
  int target = 6;
  vector<string> exp = {"1+2+3", "1*2*3"};
  l282::Solution solver;
  vector<string> act = solver.addOperators(num, target);
  sort(exp.begin(), exp.end());
  sort(act.begin(), act.end());
  EXPECT_EQ(act, exp);
}

TEST(q282, sample_input02) {
  string num = "232";
  int target = 8;
  vector<string> exp = {"2+3*2", "2*3+2"};
  l282::Solution solver;
  vector<string> act = solver.addOperators(num, target);
  sort(exp.begin(), exp.end());
  sort(act.begin(), act.end());
  EXPECT_EQ(act, exp);
}

TEST(q282, sample_input03) {
  string num = "105";
  int target = 5;
  vector<string> exp = {"1*0+5", "10-5"};
  l282::Solution solver;
  vector<string> act = solver.addOperators(num, target);
  sort(exp.begin(), exp.end());
  sort(act.begin(), act.end());
  EXPECT_EQ(act, exp);
}

TEST(q282, sample_input04) {
  string num = "00";
  int target = 0;
  vector<string> exp = {"0+0", "0-0", "0*0"};
  l282::Solution solver;
  vector<string> act = solver.addOperators(num, target);
  sort(exp.begin(), exp.end());
  sort(act.begin(), act.end());
  EXPECT_EQ(act, exp);
}

TEST(q282, sample_input05) {
  string num = "3456237490";
  int target = 9191;
  vector<string> exp;
  l282::Solution solver;
  vector<string> act = solver.addOperators(num, target);
  sort(exp.begin(), exp.end());
  sort(act.begin(), act.end());
  EXPECT_EQ(act, exp);
}

#endif