#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 936.
 *      Stamping The Sequence
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given two strings ‘stamp’ and ‘target’ . Initially, there is a
 *   string ‘s’ of length ‘target.length’ with all ‘s[i] = '?'’
 *   In one turn, you can place ‘stamp’ over ‘s’ and replace every letter
 *   in the ‘s’ with the corresponding letter from ‘stamp’
 *       - For example, if ‘stamp = 'abc'’ and ‘target = 'abcba'’ , then
 *   ‘s’ is ‘'?????'’ initially. In one turn you
 *           - place ‘stamp’ at index ‘0’ of ‘s’ to obtain ‘'abc??'’
 *           - place ‘stamp’ at index ‘1’ of ‘s’ to obtain ‘'?abc?'’ ,
 *           - place ‘stamp’ at index ‘2’ of ‘s’ to obtain ‘'??abc'’
 *       	Note that ‘stamp’ must be fully contained in the boundaries of
 *   ‘s’ in order to stamp (i.e., you cannot place ‘stamp’ at index ‘3’ of
 *   ‘s’
 *   We want to convert ‘s’ to ‘target’ using “at most” ‘10 ×
 *   target.length’
 *   Return “an array of the index of the left-most letter being stamped at
 *   each turn” . If we cannot obtain ‘target’ from ‘s’ within ‘10 ×
 *   target.length’ turns, return an empty array.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ stamp.length ≤ target.length ≤ 1000’
 *   • ‘stamp’ and ‘target’ consist of lowercase English letters.
 *
 */

struct q936 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  private:
    struct Node {
      unordered_set<int> made, todo;
    };

  public:
    vector<int> movesToStamp(string stamp, string target) {
      auto m    = static_cast<int>(stamp.size());
      auto n    = static_cast<int>(target.size());
      auto q    = queue<int>();
      auto done = vector<bool>(n, false);
      auto res  = vector<int>();
      auto lst  = vector<Node>();

      for (int i = 0; i <= n - m; ++i) {
        auto made = unordered_set<int>();
        auto todo = unordered_set<int>();

        for (int j = 0; j < m; ++j) {
          if (target[i + j] == stamp[j]) {
            made.emplace(i + j);
          } else {
            todo.emplace(i + j);
          }
        }

        if (todo.empty()) {
          res.emplace_back(i);
          for (int j = i; j < i + m; ++j) {
            if (!done[j]) {
              q.emplace(j);
              done[j] = true;
            }
          }
        }
        lst.emplace_back(Node{move(made), move(todo)});
      }

      while (!q.empty()) {
        auto i = q.front();
        q.pop();

        for (int j = max(i - m + 1, 0); j <= min(n - m, i); ++j) {
          auto &node = lst[j];
          auto &todo = node.todo;

          auto find = todo.find(i);
          if (find != todo.end()) {
            todo.erase(find);
            if (todo.empty()) {
              res.emplace_back(j);
              for (auto x : node.made) {
                if (!done[x]) {
                  q.emplace(x);
                  done[x] = true;
                }
              }
            }
          }
        }
      }

      for (auto b : done) {
        if (!b) {
          return vector<int>();
        }
      }

      reverse(res.begin(), res.end());

      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q936, sample_input01) {
  solution        = new Solution();
  string stamp    = "abc";
  string target   = "ababc";
  vector<int> exp = {1, 0, 2};
  vector<int> act = solution->movesToStamp(stamp, target);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q936, sample_input02) {
  solution        = new Solution();
  string stamp    = "abca";
  string target   = "aabcaca";
  vector<int> exp = {2, 3, 0, 1};
  vector<int> act = solution->movesToStamp(stamp, target);
  EXPECT_EQ(act, exp);
  delete solution;
}