#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/treenode.hpp>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 513.
 *      Find Bottom Left Tree Value
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given the ‘root’ of a binary tree, return the leftmost value in the
 *   last row of the tree.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • The number of nodes in the tree is in the range ‘[1, 10⁴]’ .
 *   • ‘-2³¹ ≤ Node.val ≤ 2³¹ - 1’
 *
 */

struct q513 : public ::testing::Test {
  // Leetcode answer here

  /**
   * Definition for a binary tree node.
   * struct TreeNode {
   *     int val;
   *     TreeNode *left;
   *     TreeNode *right;
   *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
   *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
   * right(right) {}
   * };
   */
  class Solution {
  private:
    void solve(TreeNode *p, int *tgt, int *tgt_lvl, int lvl) {
      if (nullptr != p) {
        if (lvl > *tgt_lvl) {
          *tgt_lvl = lvl;
          *tgt     = p->val;
        }

        solve(p->left, tgt, tgt_lvl, lvl + 1);
        solve(p->right, tgt, tgt_lvl, lvl + 1);
      }
    }

  public:
    int findBottomLeftValue(TreeNode *root) {
      auto res = (int)0;
      auto lvl = (int)-1;
      solve(root, &res, &lvl, 0);
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q513, sample_input01) {
  solution       = new Solution();
  TreeNode *root = TreeNode::generate({2, 1, 3});
  int       exp  = 1;
  int       act  = solution->findBottomLeftValue(root);
  EXPECT_EQ(act, exp);
  TreeNode::release(root);
  delete solution;
}

TEST_F(q513, sample_input02) {
  solution       = new Solution();
  TreeNode *root = TreeNode::generate(
      {1, 2, 3, 4, NULL_TREENODE, 5, 6, NULL_TREENODE, NULL_TREENODE, 7});
  int exp = 7;
  int act = solution->findBottomLeftValue(root);
  EXPECT_EQ(act, exp);
  TreeNode::release(root);
  delete solution;
}