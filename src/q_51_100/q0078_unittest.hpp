
#ifndef Q78_UNITTEST_H__
#define Q78_UNITTEST_H__
#include <gtest/gtest.h>

#include <leetcode/anyorder.hpp>

#include "q0078.hpp"
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * #78
  *     Subsets
  *
  *============================= Description =============================
  *
  *   Given an integer array ‘nums‘ of “unique” elements, return all
  *   possible subsets (the power set).
  *   
  *   The solution set “must not” contain duplicate subsets. Return the
  *   solution in “any order”.
  *
  * ============================= Constraints =============================
  *
  *   • ‘1 <= nums.length <= 10‘
  *   • ‘-10 <= nums[i] <= 10‘
  *   • All the numbers of ‘nums‘ are “unique” .
  *
*/

TEST(q78, sample_input01) {
  l78::Solution solver;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> exp = {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}};
  EXPECT_EQ_ANY_ORDER(solver.subsets(nums), exp);
}

TEST(q78, sample_input02) {
  l78::Solution solver;
  vector<int> nums = {0};
  vector<vector<int>> exp = {{}, {0}};
  EXPECT_EQ(solver.subsets(nums), exp);
}

#endif