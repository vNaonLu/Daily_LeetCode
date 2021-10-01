
#ifndef Q160_UNITTEST_H__
#define Q160_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0160.hpp"
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 160.
  *      Intersection of Two Linked Lists
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   Given the heads of two singly linked-lists ‘headA’ and ‘headB’ ,
  *   return “the node at which the two lists intersect” . If the two linked
  *   lists have no intersection at all, return ‘null’.
  *   
  *   For example, the following two linked lists begin to intersect at node
  *   ‘c1’.
  *   
  *   The test cases are generated such that there are no cycles anywhere in
  *   the entire linked structure.
  *   
  *   “Note” that the linked lists must “retain their original structure”
  *   after the function returns.
  *   
  *   “Custom Judge:”.
  *   
  *   The inputs to the “judge” are given as follows (your program is “not”
  *   given these.
  *   
  *   - ‘intersectVal’ - The value of the node where the intersection
  *   occurs. This is ‘0’ if there is no intersected node.
  *   
  *   - ‘listA’ - The first linked list.
  *   
  *   - ‘listB’ - The second linked list.
  *   
  *   - ‘skipA’ - The number of nodes to skip ahead in ‘listA’ (starting
  *   from the head) to get to the intersected node.
  *   
  *   - ‘skipB’ - The number of nodes to skip ahead in ‘listB’ (starting
  *   from the head) to get to the intersected node.
  *   
  *   The judge will then create the linked structure based on these inputs
  *   and pass the two heads, ‘headA’ and ‘headB’ to your program. If you
  *   correctly return the intersected node, then your solution will be
  *   “accepted”.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • The number of nodes of ‘listA’ is in the ‘m’ .
  *   • The number of nodes of ‘listB’ is in the ‘n’ .
  *   • ‘0 ≤ m, n ≤ 3 × 10⁴’
  *   • ‘1 ≤ Node.val ≤ 10⁵’
  *   • ‘0 ≤ skipA ≤ m’
  *   • ‘0 ≤ skipB ≤ n’
  *   • ‘intersectVal’ is ‘0’ if ‘listA’ and ‘listB’ do not intersect.
  *   • ‘intersectVal = listA[skipA] = listB[skipB]’ if ‘listA’ and ‘listB’ intersect.
  *
*/

TEST(q160, sample_input01) {
  l160::Solution solver;
  ListNode *intersection = ListNode::generate({8, 4, 5});
  ListNode *headA = ListNode::generate({4, 1});
  ListNode *headB = ListNode::generate({5, 6, 1});
  ListNode *exp = ListNode::generate({8, 4, 5});

  ListNode *p = headA;
  while (p->next != nullptr) {
    p = p->next;
  }
  p->next = intersection;
  p = headB;
  while (p->next != nullptr) {
    p = p->next;
  }
  p->next = intersection;

  EXPECT_LISTNODE_EQ(solver.getIntersectionNode(headA, headB), exp);
}

TEST(q160, sample_input02) {
  l160::Solution solver;
  ListNode *intersection = ListNode::generate({2, 4});
  ListNode *headA = ListNode::generate({1, 9, 1});
  ListNode *headB = ListNode::generate({3});
  ListNode *exp = ListNode::generate({2, 4});

  ListNode *p = headA;
  while (p->next != nullptr) {
    p = p->next;
  }
  p->next = intersection;
  p = headB;
  while (p->next != nullptr) {
    p = p->next;
  }
  p->next = intersection;

  EXPECT_LISTNODE_EQ(solver.getIntersectionNode(headA, headB), exp);
}

TEST(q160, sample_input03) {
  l160::Solution solver;
  ListNode *intersection = ListNode::generate({});
  ListNode *headA = ListNode::generate({2, 6, 4});
  ListNode *headB = ListNode::generate({1, 5});
  ListNode *exp = ListNode::generate({});

  EXPECT_LISTNODE_EQ(solver.getIntersectionNode(headA, headB), exp);
}

#endif