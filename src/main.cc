#include <gtest/gtest.h>
#include <leetcode/listnode.hpp>
#include <leetcode/treenode.hpp>

vector<vector<ListNode*>> ListNode::keep_ = {};
vector<vector<TreeNode>> TreeNode::keep_ = {};

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}