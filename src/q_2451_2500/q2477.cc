#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 2477.
 *       Minimum Fuel Cost to Report to the Capital
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   There is a tree (i.e., a connected, undirected graph with no cycles)
 *   structure country network consisting of ‘n’ cities numbered from ‘0’
 *   to ‘n - 1’ and exactly ‘n - 1’ roads. The capital city is city ‘0’ .
 *   You are given a 2D integer array ‘roads’ where ‘roads[i] = [aᵢ, bᵢ]’
 *   denotes that there exists a “bidirectional road” connecting cities
 *   ‘aᵢ’ and ‘bᵢ’
 *   There is a meeting for the representatives of each city. The meeting
 *   is in the capital
 *   There is a car in each city. You are given an integer ‘seats’ that
 *   indicates the number of seats in each
 *   A representative can use the car in their city to travel or change the
 *   car and ride with another representative. The cost of traveling
 *   between two cities is one liter of
 *   Return “the minimum number of liters of fuel to reach the capital
 *   city” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ n ≤ 10⁵’
 *   • ‘roads.length = n - 1’
 *   • ‘roads[i].length = 2’
 *   • ‘0 ≤ aᵢ, bᵢ < n’
 *   • ‘aᵢ ≠ bᵢ’
 *   • ‘roads’ represents a valid tree.
 *   • ‘1 ≤ seats ≤ 10⁵’
 *
 */

struct q2477 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  private:
    int dfs(int i, int prev, vector<vector<int>> &graph, int64_t &res, int &s,
            int people = 1) {
      for (auto x : graph[i]) {
        if (x == prev) {
          continue;
        }
        people += dfs(x, i, graph, res, s);
      }
      if (i != 0) {
        res += (people + s - 1) / s;
      }
      return people;
    }

  public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats) {
      int64_t             res = 0;
      vector<vector<int>> graph(roads.size() + 1);
      for (auto &v : roads) {
        graph[v[0]].emplace_back(v[1]);
        graph[v[1]].emplace_back(v[0]);
      }
      dfs(0, 0, graph, res, seats);
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q2477, sample_input01) {
  solution                  = new Solution();
  vector<vector<int>> roads = {
      {0, 1},
      {0, 2},
      {0, 3}
  };
  int  seats = 5;
  long exp   = 3;
  long act   = solution->minimumFuelCost(roads, seats);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q2477, sample_input02) {
  solution                  = new Solution();
  vector<vector<int>> roads = {
      {3, 1},
      {3, 2},
      {1, 0},
      {0, 4},
      {0, 5},
      {4, 6}
  };
  int  seats = 2;
  long exp   = 7;
  long act   = solution->minimumFuelCost(roads, seats);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q2477, sample_input03) {
  solution                  = new Solution();
  vector<vector<int>> roads = {};
  int                 seats = 1;
  long                exp   = 0;
  long                act   = solution->minimumFuelCost(roads, seats);
  EXPECT_EQ(act, exp);
  delete solution;
}