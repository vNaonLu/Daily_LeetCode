
#ifndef LEETCODE_Q39_H__
#define LEETCODE_Q39_H__
#include <iostream>
#include <vector>

namespace l39 {
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 39.
  *     Combination Sum
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   Given an array of “distinct” integers ‘candidates’ and a target
  *   integer ‘target’ , return “a list of all “unique combinations” of ”
  *   ‘candidates’ “ where the chosen numbers sum to ” ‘target’ “.” You may
  *   return the combinations in “any order”.
  *   
  *   The “same” number may be chosen from ‘candidates’ an “unlimited number
  *   of times” . Two combinations are unique if the frequency of at least
  *   one of the chosen numbers is different.
  *   
  *   It is “guaranteed” that the number of unique combinations that sum up
  *   to ‘target’ is less than ‘150’ combinations for the given input.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • ‘1 ≤ candidates.length ≤ 30’
  *   • ‘1 ≤ candidates[i] ≤ 200’
  *   • All elements of ‘candidates’ are “distinct” .
  *   • ‘1 ≤ target ≤ 500’
  *
*/

class Solution {
 private:
  void helper(vector<int> &cand, const int &t, vector<vector<int>> &r, vector<int> &c, int sum = 0, int beg = 0) {
    if (beg >= cand.size()) return;
    if (sum == t) {
      r.push_back(c);
    } else {
      for (int i = beg; i < cand.size(); ++i) {
        sum += cand[i];
        if (sum <= t) {
          c.push_back(cand[i]);
          helper(cand, t, r, c, sum, i);
          c.pop_back();
          sum -= cand[i];
        } else {
          sum -= cand[i];
          break;
        }
      }
    }
  }

 public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> tmp;
    sort(candidates.begin(), candidates.end());
    helper(candidates, target, res, tmp);
    return res;
  }
};
}  // namespace l39

#endif