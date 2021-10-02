
#ifndef LEETCODE_Q1823_H__
#define LEETCODE_Q1823_H__
#include <iostream>

namespace l1823 {
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 1823.
  *       Find the Winner of the Circular Game
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   There are ‘n’ friends that are playing a game. The friends are sitting
  *   in a circle and are numbered from ‘1’ to ‘n’ in “clockwise order” .
  *   More formally, moving clockwise from the ‘iᵗʰ’ friend brings you to
  *   the ‘(i+1)ᵗʰ’ friend for ‘1 ≤ i < n’ , and moving clockwise from the
  *   ‘nᵗʰ’ friend brings you to the ‘1ˢᵗ’ friend.
  *   
  *   The rules of the game are as.
  *   
  *   - “Start” at the ‘1ˢᵗ’ friend.
  *   
  *   - Count the next ‘k’ friends in the clockwise direction “including”
  *   the friend you started at. The counting wraps around the circle and
  *   may count some friends more than once.
  *   
  *   - The last friend you counted leaves the circle and loses the game.
  *   
  *   - If there is still more than one friend in the circle, go back to
  *   step ‘2’ “starting” from the friend “immediately clockwise” of the
  *   friend who just lost and repeat.
  *   
  *   - Else, the last friend in the circle wins the game.
  *   
  *   Given the number of friends, ‘n’ , and an integer ‘k’ , return “the
  *   winner of the game”.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • ‘1 ≤ k ≤ n ≤ 500’
  *
*/

class Solution {
 public:
  int findTheWinner(int n, int k) {
    if (n == 1) return 1;
    return (findTheWinner(n - 1, k) + k - 1) % n + 1;
  }
};
}  // namespace l1823

#endif