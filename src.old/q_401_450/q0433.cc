#include <gtest/gtest.h>
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 433.
 *      Minimum Genetic Mutation
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   A gene string can be represented by an 8-character long string, with
 *   choices from ‘'A'’ , ‘'C'’ , ‘'G'’ , and ‘'T'’
 *   Suppose we need to investigate a mutation from a gene string ‘start’
 *   to a gene string ‘end’ where one mutation is defined as one single
 *   character changed in the gene
 *       - For example, ‘'AACCGGTT' --> 'AACCGGTA'’ is one
 *   There is also a gene bank ‘bank’ that records all the valid gene
 *   mutations. A gene must be in ‘bank’ to make it a valid gene
 *   Given the two gene strings ‘start’ and ‘end’ and the gene bank ‘bank’
 *   , return “the minimum number of mutations needed to mutate from ”
 *   ‘start’ “ to ” ‘end’ . If there is no such a mutation, return ‘-1’
 *   Note that the starting point is assumed to be valid, so it might not
 *   be included in the bank.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘start.length = 8’
 *   • ‘end.length = 8’
 *   • ‘0 ≤ bank.length ≤ 10’
 *   • ‘bank[i].length = 8’
 *   • ‘start’ , ‘end’ , and ‘bank[i]’ consist of only the characters ‘['A', 'C', 'G', 'T']’ .
 *
 */

struct q433 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    inline constexpr static array<char, 4> dict = {'A', 'T', 'C', 'G'};

   public:
    int minMutation(string start, string end, vector<string> &bank) {
      unordered_set<string> bank_gene(bank.begin(), bank.end());
      unordered_set<string> changed;

      int res = 0;
      queue<string> path;
      path.emplace(start);
      changed.emplace(start);

      while (!path.empty()) {
        auto temp = move(path);

        while (!temp.empty()) {
          auto s = move(temp.front()); temp.pop();

          if (s == end) return res;

          for (int i = 0; i < 8; ++i) {
            auto origin = s[i];
            for (const auto &c : dict) {
              s[i] = c;
              if (bank_gene.count(s) && changed.emplace(s).second) {
                path.emplace(s);
              }
            }
            s[i] = origin;
          }
        }

        ++res;
      }

      return -1;
    }
  };

  class Solution *solution;
};

TEST_F(q433, sample_input01) {
  solution = new Solution();
  string start = "AACCGGTT";
  string end = "AACCGGTA";
  vector<string> bank = {"AACCGGTA"};
  int exp = 1;
  int act = solution->minMutation(start, end, bank);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q433, sample_input02) {
  solution = new Solution();
  string start = "AACCGGTT";
  string end = "AAACGGTA";
  vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
  int exp = 2;
  int act = solution->minMutation(start, end, bank);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q433, sample_input03) {
  solution = new Solution();
  string start = "AAAAACCC";
  string end = "AACCCCCC";
  vector<string> bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
  int exp = 3;
  int act = solution->minMutation(start, end, bank);
  EXPECT_EQ(act, exp);
  delete solution;
}