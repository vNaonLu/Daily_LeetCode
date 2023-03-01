// Copyright 2023 Naon Lu
//
// This file describes the solution of
// Populating Next Right Pointers in Each Node
//
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
//
// Question ID: 116
// Difficult  : Medium
// Solve Date : 2021/09/12 08:00

#include <iosfwd>

// -- This header must be included after others --
#include "leetcode/testing/solution_test_helper.h"

using namespace std;
using namespace lcd;

// Description of |116. Populating Next Right Pointers in Each Node|:
//
// You are given a perfect binary tree where all leaves are on the same level,
// and every parent has two children. The binary tree has the following
// definition: struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no
// next right node, the next pointer should be set to |NULL|. Initially, all
// next pointers are set to |NULL|.  
//

LEETCODE_BEGIN_RESOLVING(116, PopulatingNextRightPointersInEachNode, Solution);

class Node {
public:
  int   val;
  Node *left;
  Node *right;
  Node *next;
  Node() : val(0), left(NULL), right(NULL), next(NULL) {}
  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
  Node *connect(Node *root) {
    if (root == nullptr)
      return root;
    vector<vector<Node *>> level;
    level.push_back({root});
    int li = 0;
    while (li < level.size()) {
      ++li;
      auto           q = level.back();
      vector<Node *> leaves;
      for (int i = 0; i < q.size(); ++i) {
        if (i != q.size() - 1) {
          q[i]->next = q[i + 1];
        }
        if (q[i]->left != nullptr)
          leaves.push_back(q[i]->left);
        if (q[i]->right != nullptr)
          leaves.push_back(q[i]->right);
      }
      if (leaves.size() > 0)
        level.push_back(leaves);
    }
    return root;
  }
};

LEETCODE_END_RESOLVING(Solution);

///////////////////////////////////////////////////////////////////////////////
// The following is test data for unit test.
// Note that inputs should be obey the constraints mentioned in LeetCode:
// * The number of nodes in the tree is in the range |[0, 2¹² - 1]|.
// * |-1000 <= Node.val <= 1000|
// * You may only use constant extra space.
// * The recursive approach is fine. You may assume implicit stack space does
// not count as extra space for this problem.
///////////////////////////////////////////////////////////////////////////////

// [Example #1]
//  Input: root = [1,2,3,4,5,6,7]
// Output: [1,#,2,3,#,4,5,6,7,#]
//
// Given the above perfect binary tree (Figure A), your function should populate
// each next pointer to point to its next right node, just like in Figure B. The
// serialized output is in level order as connected by the next pointers, with
// '#' signifying the end of each level.

LEETCODE_SOLUTION_UNITTEST(116, PopulatingNextRightPointersInEachNode,
                           example_1) {
  GTEST_SKIP() << "Unittest Not Implemented";
}

// [Example #2]
//  Input: root = []
// Output: []
//

LEETCODE_SOLUTION_UNITTEST(116, PopulatingNextRightPointersInEachNode,
                           example_2) {
  GTEST_SKIP() << "Unittest Not Implemented";
}
