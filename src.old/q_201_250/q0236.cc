#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/treenode.hpp>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 236.
 *      Lowest Common Ancestor of a Binary Tree
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a binary tree, find the lowest common ancestor (LCA) of two
 *   given nodes in the
 *   According to the <a
 *   href="https://en.wikipedia.org/wiki/Lowest_common_ancestor"
 *   target="_blank">definition of LCA on Wikipedia</a>: “The lowest common
 *   ancestor is defined between two nodes ‘p’ and ‘q’ as the lowest node
 *   in ‘T’ that has both ‘p’ and ‘q’ as descendants (where we allow “a
 *   node to be a descendant of itself” ).”
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • The number of nodes in the tree is in the range ‘[2, 10⁵]’ .
 *   • ‘-10⁹ ≤ Node.val ≤ 10⁹’
 *   • All ‘Node.val’ are “unique” .
 *   • ‘p ≠ q’
 *   • ‘p’ and ‘q’ will exist in the tree.
 *
 */

struct q236 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  private:
    bool findPath(vector<TreeNode *> &path, TreeNode *p, TreeNode *t) {
      if (p == nullptr) {

        return false;
      } else if (p == t) {
        path.emplace_back(p);

        return true;
      } else {
        path.emplace_back(p);

        return findPath(path, p->left, t) ||
               findPath(path, p->right, t) ||
               (path.pop_back(), false);
      }
    }

  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
      vector<TreeNode *> path_p, path_q;

      if (findPath(path_p, root, p) && findPath(path_q, root, q)) {
        auto p_it = path_p.begin(),
             q_it = path_q.begin();

        while (p_it != path_p.end() && q_it != path_q.end()) {
          if (*(p_it++) != *(q_it++)) {
            return *(p_it - 2);
          }
        }

        return p_it == path_p.end() ? *(--p_it) : *(--q_it);
      }

      return nullptr;
    }
  };

  class Solution *solution;
};

TEST_F(q236, sample_input01) {
  solution = new Solution();
  TreeNode *root = TreeNode::generate({3, 5, 1, 6, 2, 0, 8, NULL_TREENODE, NULL_TREENODE, 7, 4});
  TreeNode *p = TreeNode::generate({});
  TreeNode *q = TreeNode::generate({});
  TreeNode *exp = TreeNode::generate({});
  TreeNode *act = solution->lowestCommonAncestor(root, p, q);
  EXPECT_TREENODE_EQ(act, exp);
  TreeNode::release(root, p, q, exp, act);
  delete solution;
}

TEST_F(q236, sample_input02) {
  solution = new Solution();
  TreeNode *root = TreeNode::generate({3, 5, 1, 6, 2, 0, 8, NULL_TREENODE, NULL_TREENODE, 7, 4});
  TreeNode *p = TreeNode::generate({});
  TreeNode *q = TreeNode::generate({});
  TreeNode *exp = TreeNode::generate({});
  TreeNode *act = solution->lowestCommonAncestor(root, p, q);
  EXPECT_TREENODE_EQ(act, exp);
  TreeNode::release(root, p, q, exp, act);
  delete solution;
}

TEST_F(q236, sample_input03) {
  solution = new Solution();
  TreeNode *root = TreeNode::generate({1, 2});
  TreeNode *p = TreeNode::generate({});
  TreeNode *q = TreeNode::generate({});
  TreeNode *exp = TreeNode::generate({});
  TreeNode *act = solution->lowestCommonAncestor(root, p, q);
  EXPECT_TREENODE_EQ(act, exp);
  TreeNode::release(root, p, q, exp, act);
  delete solution;
}