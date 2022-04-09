#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 134.
 *      Gas Station
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   There are ‘n’ gas stations along a circular route, where the amount of
 *   gas at the ‘iᵗʰ’ station is ‘gas[i]’
 *   You have a car with an unlimited gas tank and it costs ‘cost[i]’ of
 *   gas to travel from the ‘iᵗʰ’ station to its next ‘(i + 1)ᵗʰ’ station.
 *   You begin the journey with an empty tank at one of the gas
 *   Given two integer arrays ‘gas’ and ‘cost’ , return “the starting gas
 *   station's index if you can travel around the circuit once in the
 *   clockwise direction, otherwise return” ‘-1’ . If there exists a
 *   solution, it is “guaranteed” to be “unique” 
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘gas.length = n’
 *   • ‘cost.length = n’
 *   • ‘1 ≤ n ≤ 10⁵’
 *   • ‘0 ≤ gas[i], cost[i] ≤ 10⁴’
 *
 */

struct q134 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int total = 0,
          cur = 0,
          res = 0;
      for (int i = 0; i < gas.size(); ++i) {
        total += gas[i] - cost[i];
        cur += gas[i] - cost[i];
        if (cur < 0) {
          cur = 0;
          res = i + 1;
        }
      }
      return total < 0 ? -1 : res;
    }
  };

  class Solution *solution;
};

TEST_F(q134, sample_input01) {
  solution = new Solution();
  vector<int> gas = {1, 2, 3, 4, 5};
  vector<int> cost = {3, 4, 5, 1, 2};
  int exp = 3;
  int act = solution->canCompleteCircuit(gas, cost);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q134, sample_input02) {
  solution = new Solution();
  vector<int> gas = {2, 3, 4};
  vector<int> cost = {3, 4, 3};
  int exp = -1;
  int act = solution->canCompleteCircuit(gas, cost);
  EXPECT_EQ(act, exp);
  delete solution;
}