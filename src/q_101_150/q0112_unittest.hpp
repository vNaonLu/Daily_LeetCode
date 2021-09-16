
#ifndef Q112_UNITTEST_H__
#define Q112_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0112.hpp"
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 112. Path Sum
  *
  * Given the root of a binary tree and an integer
  * targetSum , return true if the tree has a
  * “root-to-leaf“ path such that adding up all the values along
  * the path equals targetSum .
  * A “leaf“ is a node with no children.
  *
  * Constraints:
  * - The number of nodes in the tree is in the range [0, 5000] .
  * -  -1000 <= Node.val <= 1000 
  * -  -1000 <= targetSum <= 1000 
  *
*/

TEST(q112, sample_input01) {
  int null = -1;
  TreeNode *root = TreeNode::generate({5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1}, null);
  int targetSum = 22;
  bool exp = true;
  l112::Solution solver;
  EXPECT_EQ(solver.hasPathSum(root, targetSum), exp);
  TreeNode::release(root);
}

TEST(q112, sample_input02) {
  int null = -1;
  TreeNode *root = TreeNode::generate({1, 2, 3}, null);
  int targetSum = 5;
  bool exp = false;
  l112::Solution solver;
  EXPECT_EQ(solver.hasPathSum(root, targetSum), exp);
  TreeNode::release(root);
}

TEST(q112, sample_input03) {
  int null = -1;
  TreeNode *root = TreeNode::generate({1, 2}, null);
  int targetSum = 0;
  bool exp = false;
  l112::Solution solver;
  EXPECT_EQ(solver.hasPathSum(root, targetSum), exp);
  TreeNode::release(root);
}

TEST(q112, input01) {
  int null = -1;
  TreeNode *root = TreeNode::generate({}, null);
  int targetSum = 0;
  bool exp = false;
  l112::Solution solver;
  EXPECT_EQ(solver.hasPathSum(root, targetSum), exp);
  TreeNode::release(root);
}

#endif