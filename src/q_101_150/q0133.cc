// Copyright 2023 Naon Lu
//
// This file describes the solution of
// Clone Graph
//
// https://leetcode.com/problems/clone-graph/
//
// Question ID: 133
// Difficult  : Medium
// Solve Date : 2022/02/23 18:25

#include <iosfwd>
#include <map>
#include <queue>
#include <unordered_map>

// -- This header must be included after others --
#include "leetcode/testing/solution_test_helper.h"

using namespace std;
using namespace lcd;

// Description of |133. Clone Graph|:
//
// Given a reference of a node in a [connected] undirected graph.
// Return a deep copy (clone) of the graph.
// Each node in the graph contains a value ( |int|) and a list ( |List[Node]|)
// of its neighbors. class Node {
//     public int val;
//     public List<Node> neighbors;
// }
//  
// Test case format:
// For simplicity, each node's value is the same as the node's index
// (1-indexed). For example, the first node with |val == 1|, the second node
// with |val == 2|, and so on. The graph is represented in the test case using
// an adjacency list. An adjacency list is a collection of unordered lists used
// to represent a finite graph. Each list describes the set of neighbors of a
// node in the graph. The given node will always be the first node with |val =
// 1|. You must return the copy of the given node as a reference to the cloned
// graph.  
//

LEETCODE_BEGIN_RESOLVING(133, CloneGraph, Solution);

class Node {
public:
  int            val;
  vector<Node *> neighbors;
  Node() {
    val       = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val       = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val       = _val;
    neighbors = _neighbors;
  }
};

class Solution {
private:
  using graph_t = unordered_map<int, pair<Node *, vector<int>>>;
  inline graph_t buildGraph(Node *p) {
    graph_t       res;
    queue<Node *> q;
    q.emplace(p);
    while (!q.empty()) {
      Node *curr = q.front();
      q.pop();
      if (res.find(curr->val) == res.end()) {
        res[curr->val] = make_pair(new Node(curr->val), vector<int>{});
        auto &ins      = res[curr->val];
        for (auto it = curr->neighbors.begin(); it != curr->neighbors.end();
             ++it) {
          ins.second.emplace_back((*it)->val);
          q.emplace(*it);
        }
      }
    }
    return res;
  }

  inline void connectNode(graph_t &g) {
    for (auto &[key, val] : g) {
      auto &[node, next] = val;
      for (auto it = next.begin(); it != next.end(); ++it) {
        node->neighbors.emplace_back(g[*it].first);
      }
    }
  }

public:
  Node *cloneGraph(Node *node) {
    if (nullptr == node)
      return nullptr;
    auto graph = buildGraph(node);
    connectNode(graph);
    return graph[node->val].first;
  }
};

LEETCODE_END_RESOLVING(Solution);

///////////////////////////////////////////////////////////////////////////////
// The following is test data for unit test.
// Note that inputs should be obey the constraints mentioned in LeetCode:
// * The number of nodes in the graph is in the range |[0, 100]|.
// * |1 <= Node.val <= 100|
// * |Node.val| is unique for each node.
// * There are no repeated edges and no self-loops in the graph.
// * The Graph is connected and all nodes can be visited starting from the given
// node.
///////////////////////////////////////////////////////////////////////////////

// [Example #1]
//  Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
// Output: [[2,4],[1,3],[2,4],[1,3]]
//
// There are 4 nodes in the graph.
// 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

LEETCODE_SOLUTION_UNITTEST(133, CloneGraph, example_1) {
  GTEST_SKIP() << "Unittest Not Implemented";
}

// [Example #2]
//  Input: adjList = [[]]
// Output: [[]]
//
// Note that the input contains one empty list. The graph consists of only one
// node with val = 1 and it does not have any neighbors.

LEETCODE_SOLUTION_UNITTEST(133, CloneGraph, example_2) {
  GTEST_SKIP() << "Unittest Not Implemented";
}

// [Example #3]
//  Input: adjList = []
// Output: []
//
// This an empty graph, it does not have any nodes.

LEETCODE_SOLUTION_UNITTEST(133, CloneGraph, example_3) {
  GTEST_SKIP() << "Unittest Not Implemented";
}
