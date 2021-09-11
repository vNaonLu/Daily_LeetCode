
#ifndef LEETCODE_Q21_H__
#define LEETCODE_Q21_H__
#include <iostream>

#include "leetcode_struct/list_node.hpp"

namespace l21 {
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 21. Merge Two Sorted Lists
  *
  * Merge two sorted linked lists and return it as a
  * “sorted“ list. The list should be made by splicing
  * together the nodes of the first two lists.
  *
  * Constraints:
  * - The number of nodes in both lists is in the range [0, 50] .
  * -  -100 <= Node.val <= 100 
  * - Both l1 and l2 are sorted in “non-decreasing“ order.
  *
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* res = nullptr;
    if (l1 != nullptr && l2 != nullptr) {
      if (l1->val <= l2->val) {
        res = l1;
        l1 = l1->next;
      } else {
        res = l2;
        l2 = l2->next;
      }
    } else if (l1 != nullptr) {
      res = l1;
      l1 = l1->next;
    } else if (l2 != nullptr) {
      res = l2;
      l2 = l2->next;
    }

    ListNode* p = res;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val <= l2->val) {
        p->next = l1;
        l1 = l1->next;
      } else {
        p->next = l2;
        l2 = l2->next;
      }
      p = p->next;
    }

    while (l1 != nullptr) {
      p->next = l1;
      p = p->next;
      l1 = l1->next;
    }
    while (l2 != nullptr) {
      p->next = l2;
      p = p->next;
      l2 = l2->next;
    }
    return res;
  }
};
}  // namespace l21
#endif