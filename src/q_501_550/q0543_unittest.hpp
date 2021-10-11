
#ifndef Q543_UNITTEST_H__
#define Q543_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0543.hpp"
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 543.
  *      Diameter of Binary Tree
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   Given the ‘root’ of a binary tree, return “the length of the
  *   “diameter” of the tree”.
  *   
  *   The “diameter” of a binary tree is the “length” of the longest path
  *   between any two nodes in a tree. This path may or may not pass through
  *   the ‘root’.
  *   
  *   The “length” of a path between two nodes is represented by the number
  *   of edges between them.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • The number of nodes in the tree is in the range ‘[1, 10⁴]’ .
  *   • ‘-100 ≤ Node.val ≤ 100’
  *
*/

TEST(q543, sample_input01) {
  l543::Solution solver;
  TreeNode* root = TreeNode::generate({1, 2, 3, 4, 5});
  int exp = 3;
  EXPECT_EQ(solver.diameterOfBinaryTree(root), exp);
}

TEST(q543, sample_input02) {
  l543::Solution solver;
  TreeNode* root = TreeNode::generate({1, 2});
  int exp = 1;
  EXPECT_EQ(solver.diameterOfBinaryTree(root), exp);
}

TEST(q543, input01) {
  l543::Solution solver;
  TreeNode* root = TreeNode::generate({4,-7,-3,NULL_TREENODE,NULL_TREENODE,-9,-3,9,-7,-4,NULL_TREENODE,6,NULL_TREENODE,-6,-6,NULL_TREENODE,NULL_TREENODE,0,6,5,NULL_TREENODE,9,NULL_TREENODE,NULL_TREENODE,-1,-4,NULL_TREENODE,NULL_TREENODE,NULL_TREENODE,-2});
  int exp = 8;
  EXPECT_EQ(solver.diameterOfBinaryTree(root), exp);
}

#endif