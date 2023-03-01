#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 1014.
 *       Best Sightseeing Pair
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given an integer array ‘values’ where values[i] represents the
 *   value of the ‘iᵗʰ’ sightseeing spot. Two sightseeing spots ‘i’ and ‘j’
 *   have a “distance” ‘j - i’ between
 *   The score of a pair ( ‘i < j’ ) of sightseeing spots is ‘values[i] +
 *   values[j] + i - j’ : the sum of the values of the sightseeing spots,
 *   minus the distance between
 *   Return “the maximum score of a pair of sightseeing spots” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘2 ≤ values.length ≤ 5 × 10⁴’
 *   • ‘1 ≤ values[i] ≤ 1000’
 *
 */

struct q1014 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int maxScoreSightseeingPair(vector<int>& values) {
      int res = 0;
      int i = 0, dist = 1;
      while (i + dist < values.size()) {
        res = max(res, values[i] + values[i + dist] - dist);
        if (values[i] - dist <= values[i + dist]) {
          i += dist;
          dist = 1;
        } else {
          ++dist;
        }
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1014, sample_input01) {
  solution = new Solution();
  vector<int> values = {8, 1, 5, 2, 6};
  int exp = 11;
  EXPECT_EQ(solution->maxScoreSightseeingPair(values), exp);
  delete solution;
}

TEST_F(q1014, sample_input02) {
  solution = new Solution();
  vector<int> values = {1, 2};
  int exp = 2;
  EXPECT_EQ(solution->maxScoreSightseeingPair(values), exp);
  delete solution;
}