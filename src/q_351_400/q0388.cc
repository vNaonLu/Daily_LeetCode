#include <gtest/gtest.h>
#include <iostream>
#include <numeric>
#include <string>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 388.
 *      Longest Absolute File Path
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Suppose we have a file system that stores both files and directories.
 *   An example of one system is represented in the following
 *   Here, we have ‘dir’ as the only directory in the root. ‘dir’ contains
 *   two subdirectories, ‘subdir1’ and ‘subdir2’ . ‘subdir1’ contains a
 *   file ‘file1.ext’ and subdirectory ‘subsubdir1’ . ‘subdir2’ contains a
 *   subdirectory ‘subsubdir2’ , which contains a file ‘file2.ext’
 *   In text form, it looks like this (with ⟶ representing the tab
 *   ⟶
 *   ⟶ ⟶
 *   ⟶ ⟶
 *   ⟶
 *   ⟶ ⟶
 *   ⟶ ⟶ ⟶
 *   If we were to write this representation in code, it will look like
 *   this:
 *   ile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext'’
 *   . Note that the ‘'\n'’ and ‘'\t'’ are the new-line and tab
 *   Every file and directory has a unique “absolute path” in the file
 *   system, which is the order of directories that must be opened to reach
 *   the file/directory itself, all concatenated by ‘'/'s’ . Using the
 *   above example, the “absolute path” to ‘file2.ext’ is
 *   ‘'dir/subdir2/subsubdir2/file2.ext'’ . Each directory name consists of
 *   letters, digits, and/or spaces. Each file name is of the form
 *   ‘name.extension’ , where ‘name’ and ‘extension’ consist of letters,
 *   digits, and/or
 *   Given a string ‘input’ representing the file system in the explained
 *   format, return “the length of the “longest absolute path” to a “file”
 *   in the abstracted file system” . If there is no file in the system,
 *   return ‘0’ .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ input.length ≤ 10⁴’
 *   • ‘input’ may contain lowercase or uppercase English letters, a new line character ‘'\n'’ , a tab character ‘'\t'’ , a dot ‘'.'’ , a space ‘' '’ , and digits.
 *
 */

struct q388 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int lengthLongestPath(string input) {
      int         res = 0,
                  ptr = 0,
                  cur = 0,
                  indent = 0;
      bool        is_file = false;
      vector<int> pathes(1001, 0);
      for (auto it = input.begin(); it != input.end(); ++it) {
        switch (*it) {
          case '\n':
            break;
          case '\t':
            ++indent;
            break;
          case '.':
            is_file = true;
            [[fallthrough]];
          default:
            ++cur;
        }
        if (*it == '\n' || it + 1 == input.end()) {
          if (ptr == indent) {
            /// next depth
            pathes[ptr++] = cur;
            if (is_file) {
              res = max(res, accumulate(pathes.begin(), pathes.begin() + ptr, 0) + indent);
            }
            cur = indent = 0;
            is_file = false;
          } else {
            /// indent is not possible bigger than ptr
            ptr = indent;
            pathes[ptr++] = cur;
            if (is_file) {
              res = max(res, accumulate(pathes.begin(), pathes.begin() + ptr, 0) + indent);
            }
            cur = indent = 0;
            is_file = false;
          }
        }
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q388, sample_input01) {
  solution = new Solution();
  string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
  int exp = 20;
  int act = solution->lengthLongestPath(input);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q388, sample_input02) {
  solution = new Solution();
  string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
  int exp = 32;
  int act = solution->lengthLongestPath(input);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q388, sample_input03) {
  solution = new Solution();
  string input = "a";
  int exp = 0;
  int act = solution->lengthLongestPath(input);
  EXPECT_EQ(act, exp);
  delete solution;
}