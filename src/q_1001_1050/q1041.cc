#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1041.
 *       Robot Bounded In Circle
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   On an infinite plane, a robot initially stands at ‘(0, 0)’ and faces
 *   north. The robot can receive one of three
 *       -  ‘'G'’ : go straight 1
 *       -  ‘'L'’ : turn 90 degrees to the
 *       -  ‘'R'’ : turn 90 degrees to the
 *   The robot performs the ‘instructions’ given in order, and repeats them
 *   Return ‘true’ if and only if there exists a circle in the plane such
 *   that the robot never leaves the circle.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ instructions.length ≤ 100’
 *   • ‘instructions[i]’ is ‘'G'’ , ‘'L'’ or, ‘'R'’ .
 *
 */

struct q1041 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    bool isOrigin(int x, int y) {
      return x == 0 && y == 0;
    }

   public:
    bool isRobotBounded(string instructions) {
      char current_dir = 'N';
      int x = 0, y = 0;
      for (const auto &instruct : instructions) {
        if (instruct == 'G') {
          switch (current_dir) {
            case 'N':
              y += 1;
              break;
            case 'W':
              x += 1;
              break;
            case 'S':
              y -= 1;
              break;
            case 'E':
              x -= 1;
              break;
            default:
              break;
          }
        } else {
          switch (current_dir) {
            case 'N':
              current_dir = instruct == 'L' ? 'W' : 'E';
              break;
            case 'W':
              current_dir = instruct == 'L' ? 'S' : 'N';
              break;
            case 'S':
              current_dir = instruct == 'L' ? 'E' : 'W';
              break;
            case 'E':
              current_dir = instruct == 'L' ? 'N' : 'S';
              break;
            default:
              break;
          }
        }
      }
      return isOrigin(x, y) || current_dir != 'N';
    }
  };

  class Solution *solution;
};

TEST_F(q1041, sample_input01) {
  solution = new Solution();
  string instructions = "GGLLGG";
  bool exp = true;
  bool act = solution->isRobotBounded(instructions);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1041, sample_input02) {
  solution = new Solution();
  string instructions = "GG";
  bool exp = false;
  bool act = solution->isRobotBounded(instructions);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1041, sample_input03) {
  solution = new Solution();
  string instructions = "GL";
  bool exp = true;
  bool act = solution->isRobotBounded(instructions);
  EXPECT_EQ(act, exp);
  delete solution;
}