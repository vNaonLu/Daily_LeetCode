
#ifndef LEETCODE_Q222_H__
#define LEETCODE_Q222_H__
#include <iostream>
#include <leetcode/treenode.hpp>

namespace l222 {
using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 222.
 *      Count Complete Tree Nodes
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given the ‘root’ of a “complete” binary tree, return the number of the
 *   nodes in the
 *   According to “<a
 *   href="http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees"
 *   target="_blank">Wikipedia</a>” , every level, except possibly the
 *   last, is completely filled in a complete binary tree, and all nodes in
 *   the last level are as far left as possible. It can have between ‘1’
 *   and ‘2ʰ’ nodes inclusive at the last level ‘h’
 *   Design an algorithm that runs in less than<code
 *   data-stringify-type="code">O(n)</code>time complexity.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • The number of nodes in the tree is in the range ‘[0, 5 × 10⁴]’ .
 *   • ‘0 ≤ Node.val ≤ 5 × 10⁴’
 *   • The tree is guaranteed to be “complete” .
 *
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
}  // namespace l222

#endif