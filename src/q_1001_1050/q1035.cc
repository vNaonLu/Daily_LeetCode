// Copyright 2023 Naon Lu
//
// This file describes the solution of
// Uncrossed Lines
//
// https://leetcode.com/problems/uncrossed-lines/
//
// Question ID: 1035
// Difficult  : Medium
// Solve Date : 2022/03/26 11:56

#include <iosfwd>
#include <map>
#include <unordered_map>
#include <vector>

// -- This header must be included after others --
#include "leetcode/testing/solution_test_helper.h"

using namespace std;
using namespace lcd;

// Description of |1035. Uncrossed Lines|:
//
// You are given two integer arrays |nums1| and |nums2|. We write the integers
// of |nums1| and |nums2| (in the order they are given) on two separate
// horizontal lines. We may draw connecting lines: a straight line connecting
// two numbers |nums1[i]| and |nums2[j]| such that:
//
//  • |nums1[i] == nums2[j]|, and
//
//  • the line we draw does not intersect any other connecting (non-horizontal)
//  line.
// Note that a connecting line cannot intersect even at the endpoints (i.e.,
// each number can only belong to one connecting line). Return the maximum
// number of connecting lines we can draw in this way.  
//

LEETCODE_BEGIN_RESOLVING(1035, UncrossedLines, Solution);

class Solution {
private:
  unordered_map<int, int> memos;
  int                     n;

  int encode(int i, int j) { return i * n + j; }

  int helper(vector<int> &nums1, int i1, vector<int> &nums2, int i2) {
    if (i1 >= nums1.size() || i2 >= nums2.size()) {
      return 0;
    }

    if (memos.count(encode(i1, i2))) {
      return memos[encode(i1, i2)];
    }

    int res =
        max(helper(nums1, i1, nums2, i2 + 1), helper(nums1, i1 + 1, nums2, i2));
    res = max(res, helper(nums1, i1 + 1, nums2, i2 + 1) +
                       (nums1[i1] == nums2[i2] ? 1 : 0));

    return memos[encode(i1, i2)] = res;
  }

public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    n = nums2.size();
    return helper(nums1, 0, nums2, 0);
  }
};

LEETCODE_END_RESOLVING(Solution);

///////////////////////////////////////////////////////////////////////////////
// The following is test data for unit test.
// Note that inputs should be obey the constraints mentioned in LeetCode:
// * |1 <= nums1.length, nums2.length <= 500|
// * |1 <= nums1[i], nums2[j] <= 2000|
///////////////////////////////////////////////////////////////////////////////

// [Example #1]
//  Input: nums1 = [1,4,2], nums2 = [1,2,4]
// Output: 2
//
// We can draw 2 uncrossed lines as in the diagram.
// We cannot draw 3 uncrossed lines, because the line from nums1[1] = 4 to
// nums2[2] = 4 will intersect the line from nums1[2]=2 to nums2[1]=2.

LEETCODE_SOLUTION_UNITTEST(1035, UncrossedLines, example_1) {
  auto        solution = MakeSolution();
  vector<int> nums1    = {1, 4, 2};
  vector<int> nums2    = {1, 2, 4};
  int         expect   = 2;
  int         actual   = solution->maxUncrossedLines(nums1, nums2);
  LCD_EXPECT_EQ(expect, actual);
}

// [Example #2]
//  Input: nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
// Output: 3
//

LEETCODE_SOLUTION_UNITTEST(1035, UncrossedLines, example_2) {
  auto        solution = MakeSolution();
  vector<int> nums1    = {2, 5, 1, 2, 5};
  vector<int> nums2    = {10, 5, 2, 1, 5, 2};
  int         expect   = 3;
  int         actual   = solution->maxUncrossedLines(nums1, nums2);
  LCD_EXPECT_EQ(expect, actual);
}

// [Example #3]
//  Input: nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
// Output: 2
//

LEETCODE_SOLUTION_UNITTEST(1035, UncrossedLines, example_3) {
  auto        solution = MakeSolution();
  vector<int> nums1    = {1, 3, 7, 1, 7, 5};
  vector<int> nums2    = {1, 9, 2, 5, 1};
  int         expect   = 2;
  int         actual   = solution->maxUncrossedLines(nums1, nums2);
  LCD_EXPECT_EQ(expect, actual);
}
