#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/listnode.hpp>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 2.
 *    Add Two Numbers
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given two “non-empty” linked lists representing two
 *   non-negative integers. The digits are stored in “reverse order” , and
 *   each of their nodes contains a single digit. Add the two numbers and
 *   return the sumas a linked
 *   You may assume the two numbers do not contain any leading zero, except
 *   the number 0 itself.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • The number of nodes in each linked list is in the range ‘[1, 100]’ .
 *   • ‘0 ≤ Node.val ≤ 9’
 *   • It is guaranteed that the list represents a number that does not have leading zeros.
 *
 */

struct q2 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode dummy(0);
      ListNode* res = &dummy;
      ListNode *p = l1, *q = l2;
      int carry = 0;
      while (p != nullptr || q != nullptr) {
        int x = p == nullptr ? 0 : p->val;
        int y = q == nullptr ? 0 : q->val;
        int sum = x + y + carry;
        carry = sum / 10;
        res->next = new ListNode(sum % 10);
        res = res->next;
        if (p != nullptr) p = p->next;
        if (q != nullptr) q = q->next;
      }
      if (carry != 0) res->next = new ListNode(carry);
      return dummy.next;
    }
  };

  class Solution *solution;
};

TEST_F(q2, sample_input01) {
  solution = new Solution();
  ListNode* l1 = ListNode::generate({2, 4, 3});
  ListNode* l2 = ListNode::generate({5, 6, 4});
  ListNode* exp = ListNode::generate({7, 0, 8});
  ListNode* act = solution->addTwoNumbers(l1, l2);
  EXPECT_LISTNODE_EQ(act, exp);
  ListNode::release(l1, l2, exp, act);
  delete solution;
}

TEST_F(q2, sample_input02) {
  solution = new Solution();
  ListNode* l1 = ListNode::generate({0});
  ListNode* l2 = ListNode::generate({0});
  ListNode* exp = ListNode::generate({0});
  ListNode* act = solution->addTwoNumbers(l1, l2);
  EXPECT_LISTNODE_EQ(act, exp);
  ListNode::release(l1, l2, exp, act);
  delete solution;
}

TEST_F(q2, sample_input03) {
  solution = new Solution();
  ListNode* l1 = ListNode::generate({9, 9, 9, 9, 9, 9, 9});
  ListNode* l2 = ListNode::generate({9, 9, 9, 9});
  ListNode* exp = ListNode::generate({8, 9, 9, 9, 0, 0, 0, 1});
  ListNode* act = solution->addTwoNumbers(l1, l2);
  EXPECT_LISTNODE_EQ(act, exp);
  ListNode::release(l1, l2, exp, act);
  delete solution;
}