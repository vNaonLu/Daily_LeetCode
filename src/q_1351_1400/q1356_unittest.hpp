
#ifndef Q1356_UNITTEST_H__
#define Q1356_UNITTEST_H__
#include <gtest/gtest.h>

#include "q1356.hpp"
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 1356.
  *       Sort Integers by The Number of 1 Bits
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   Given an integer array ‘arr’ . You have to sort the integers in the
  *   arrayin ascending order by the number of “1's” in their binary
  *   representation and in case of two or more integers have the same
  *   number of “1's” you have to sort them in ascending order.
  *   
  *   Return “the sorted array”.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • ‘1 ≤ arr.length ≤ 500’
  *   • ‘0 ≤ arr[i] ≤ 10^4’
  *
*/

TEST(q1356, sample_input01) {
  l1356::Solution solver;
  vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  vector<int> exp = {0, 1, 2, 4, 8, 3, 5, 6, 7};
  EXPECT_EQ(solver.sortByBits(arr), exp);
}

TEST(q1356, sample_input02) {
  l1356::Solution solver;
  vector<int> arr = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
  vector<int> exp = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
  EXPECT_EQ(solver.sortByBits(arr), exp);
}

TEST(q1356, sample_input03) {
  l1356::Solution solver;
  vector<int> arr = {10000, 10000};
  vector<int> exp = {10000, 10000};
  EXPECT_EQ(solver.sortByBits(arr), exp);
}

TEST(q1356, sample_input04) {
  l1356::Solution solver;
  vector<int> arr = {2, 3, 5, 7, 11, 13, 17, 19};
  vector<int> exp = {2, 3, 5, 17, 7, 11, 13, 19};
  EXPECT_EQ(solver.sortByBits(arr), exp);
}

TEST(q1356, sample_input05) {
  l1356::Solution solver;
  vector<int> arr = {10, 100, 1000, 10000};
  vector<int> exp = {10, 100, 10000, 1000};
  EXPECT_EQ(solver.sortByBits(arr), exp);
}

#endif