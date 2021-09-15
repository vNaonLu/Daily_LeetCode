
#ifndef Q77_UNITTEST_H__
#define Q77_UNITTEST_H__
#include <gtest/gtest.h>

#include <algorithm>

#include "q0077.hpp"
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 77. Combinations
  *
  * Given two integers n and k , return all possible
  * combinations of k numbers out of the range [1, n]
  * .
  * You may return the answer in “any order“ .
  *
  * Constraints:
  * -  1 <= n <= 20 
  * -  1 <= k <= n 
  *
*/

TEST(q77, sample_input01) {
  l77::Solution solver;
  vector<vector<int>> act = solver.combine(4, 2);
  vector<vector<int>> exp = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
  sort(act.begin(), act.end());
  sort(exp.begin(), exp.end());
  EXPECT_EQ(act, exp);
}

TEST(q77, sample_input02) {
  l77::Solution solver;
  vector<vector<int>> act = solver.combine(1, 1);
  vector<vector<int>> exp{{1}};
  sort(act.begin(), act.end());
  sort(exp.begin(), exp.end());
  EXPECT_EQ(act, exp);
}

#endif