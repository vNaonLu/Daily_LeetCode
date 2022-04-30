#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/listnode.hpp>
#include <leetcode/treenode.hpp>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1367.
 *       Linked List in Binary Tree
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a binary tree ‘root’ and alinked list with ‘head’ as the first
 *   Return True if all the elements in the linked list starting from the
 *   ‘head’ correspond to some “downward path” connected in the binary
 *   treeotherwise return
 *   In this context downward path means a path that starts at some node
 *   and goes downwards.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • The number of nodes in the tree will be in the range ‘[1, 2500]’ .
 *   • The number of nodes in the list will be in the range ‘[1, 100]’ .
 *   • ‘1 ≤ Node.val≤ 100’ for each node in the linked list and binary tree.
 *
 */

struct q1367 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    bool match(ListNode* head, TreeNode* root) {
      if (head == nullptr) return true;
      if (root == nullptr || root->val != head->val) return false;
      return match(head->next, root->left) || match(head->next, root->right);
    }
    bool dfs(ListNode* head, TreeNode* root) {
      if (root == nullptr) return false;
      if (match(head, root)) return true;
      return dfs(head, root->left) || dfs(head, root->right);
    }

   public:
    bool isSubPath(ListNode* head, TreeNode* root) {
      return dfs(head, root);
    }
  };

  class Solution *solution;
};

TEST_F(q1367, sample_input01) {
  solution = new Solution();
  ListNode* head = ListNode::generate({4, 2, 8});
  TreeNode* root = TreeNode::generate({1, 4, 4, NULL_TREENODE, 2, 2, NULL_TREENODE, 1, NULL_TREENODE, 6, 8, NULL_TREENODE, NULL_TREENODE, NULL_TREENODE, NULL_TREENODE, 1, 3});
  bool exp = true;
  bool act = solution->isSubPath(head, root);
  EXPECT_EQ(act, exp);
  ListNode::release(head);
  TreeNode::release(root);
  delete solution;
}

TEST_F(q1367, sample_input02) {
  solution = new Solution();
  ListNode* head = ListNode::generate({1, 4, 2, 6});
  TreeNode* root = TreeNode::generate({1, 4, 4, NULL_TREENODE, 2, 2, NULL_TREENODE, 1, NULL_TREENODE, 6, 8, NULL_TREENODE, NULL_TREENODE, NULL_TREENODE, NULL_TREENODE, 1, 3});
  bool exp = true;
  bool act = solution->isSubPath(head, root);
  EXPECT_EQ(act, exp);
  ListNode::release(head);
  TreeNode::release(root);
  delete solution;
}

TEST_F(q1367, sample_input03) {
  solution = new Solution();
  ListNode* head = ListNode::generate({1, 4, 2, 6, 8});
  TreeNode* root = TreeNode::generate({1, 4, 4, NULL_TREENODE, 2, 2, NULL_TREENODE, 1, NULL_TREENODE, 6, 8, NULL_TREENODE, NULL_TREENODE, NULL_TREENODE, NULL_TREENODE, 1, 3});
  bool exp = false;
  bool act = solution->isSubPath(head, root);
  EXPECT_EQ(act, exp);
  ListNode::release(head);
  TreeNode::release(root);
  delete solution;
}