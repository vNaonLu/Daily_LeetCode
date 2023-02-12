#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/treenode.hpp>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 965.
 *      Univalued Binary Tree
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   A binary tree is “uni-valued” if every node in the tree has the same
 *   Given the ‘root’ of a binary tree, return ‘true’ “ if the given tree
 *   is “uni-valued” , or ” ‘false’ “ otherwise.”
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • The number of nodes in the tree is in the range ‘[1, 100]’ .
 *   • ‘0 ≤ Node.val < 100’
 *
 */

struct q965 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    bool isUnivalTree(TreeNode *root) {
      if (nullptr == root) {
        return true;
      }
      auto left = nullptr == root->left ||
                  (root->val == root->left->val && isUnivalTree(root->left));
      auto right = nullptr == root->right ||
                   (root->val == root->right->val && isUnivalTree(root->right));
      return left && right;
    }
  };

  class Solution *solution;
};

TEST_F(q965, sample_input01) {
  solution       = new Solution();
  TreeNode *root = TreeNode::generate({1, 1, 1, 1, 1, NULL_TREENODE, 1});
  bool      exp  = true;
  bool      act  = solution->isUnivalTree(root);
  EXPECT_EQ(act, exp);
  TreeNode::release(root);
  delete solution;
}

TEST_F(q965, sample_input02) {
  solution       = new Solution();
  TreeNode *root = TreeNode::generate({2, 2, 2, 5, 2});
  bool      exp  = false;
  bool      act  = solution->isUnivalTree(root);
  EXPECT_EQ(act, exp);
  TreeNode::release(root);
  delete solution;
}