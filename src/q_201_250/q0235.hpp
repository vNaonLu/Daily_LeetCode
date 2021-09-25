
#ifndef LEETCODE_Q235_H__
#define LEETCODE_Q235_H__
#include <iostream>
#include <leetcode/treenode.hpp>

namespace l235 {
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 235. Lowest Common Ancestor of a Binary Search Tree
  *
  * Given a binary search tree (BST), find the lowest
  * common ancestor (LCA) of two given nodes in the
  * BST.
  * According to the <a
  * href="https://en.wikipedia.org/wiki/Lowest_common_ancestor"
  * target="_blank">definition of LCA on Wikipedia</a>: “The lowest
  * common ancestor is defined between two nodes p and q as
  * the lowest node in T that has both p and q as
  * descendants (where we allow  “a node to be a
  * descendant of itself” ).”
  *
  * Constraints:
  * - The number of nodes in the tree is in the range [2, 10^(5)] .
  * -  -10^(9) <= Node.val <= 10^(9) 
  * - All Node.val are “unique“ .
  * -  p != q 
  * -  p and q will exist in the BST.
  *
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
 private:
  bool isChild(TreeNode* root, TreeNode* p) {
    if (root == p)
      return true;
    else if (root == nullptr)
      return false;
    else
      return isChild(root->right, p) || isChild(root->left, p);
  }

 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == p || root == q) return root;
    auto p_exsit_right = isChild(root->right, p);
    auto q_exsit_right = isChild(root->right, q);

    if (p_exsit_right && q_exsit_right)
      return lowestCommonAncestor(root->right, p, q);
    else if (!p_exsit_right && !q_exsit_right)
      return lowestCommonAncestor(root->left, p, q);
    else
      return root;
  }
};
}  // namespace l235
#endif