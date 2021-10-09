
#ifndef Q347_UNITTEST_H__
#define Q347_UNITTEST_H__
#include <gtest/gtest.h>

#include <leetcode/anyorder.hpp>

#include "q0347.hpp"
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 347.
  *      Top K Frequent Elements
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   Given an integer array ‘nums’ and an integer ‘k’ , return “the” ‘k’
  *   “most frequent elements” . You may return the answer in “any order”.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • ‘1 ≤ nums.length ≤ 10⁵’
  *   • ‘k’ is in the range ‘[1, the number of unique elements in the array]’ .
  *   • It is “guaranteed” that the answer is “unique” .
  *
*/

TEST(q347, sample_input01) {
  l347::Solution solver;
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;
  vector<int> exp = {1, 2};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solver.topKFrequent(nums, k), exp);
}

TEST(q347, sample_input02) {
  l347::Solution solver;
  vector<int> nums = {1};
  int k = 1;
  vector<int> exp = {1};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solver.topKFrequent(nums, k), exp);
}

#endif