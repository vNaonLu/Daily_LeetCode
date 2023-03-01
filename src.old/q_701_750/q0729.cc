#include <gtest/gtest.h>
#include <iostream>
#include <set>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 729.
 *      My Calendar I
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are implementing a program to use as your calendar. We can add a
 *   new event if adding the event will not cause a “double booking”
 *   A “double booking” happens when two events have some non-empty
 *   intersection (i.e., some moment is common to both
 *   The event can be represented as a pair of integers ‘start’ and ‘end’
 *   that represents a booking on the half-open interval ‘[start, end)’ ,
 *   the range of real numbers ‘x’ such that ‘start ≤ x < end’
 *   Implement the ‘MyCalendar’
 *       -  ‘MyCalendar()’ Initializes the calendar
 *       -  ‘boolean book(int start, int end)’ Returns ‘true’ if the event
 *   can be added to the calendar successfully without causing a “double
 *   booking” . Otherwise, return ‘false’ and do not add the event to the
 *   calendar.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘0 ≤ start < end ≤ 10⁹’
 *   • At most ‘1000’ calls will be made to ‘book’ .
 *
 */

struct q729 : public ::testing::Test {
  // Leetcode answer here
  class MyCalendar {
  private:
    map<int, int> itinerary; /// end -> beg

  public:
    MyCalendar() {
    }

    bool book(int start, int end) {
      auto find = itinerary.upper_bound(start);

      if (find == itinerary.end() || end <= find->second) {
        itinerary[end] = start;

        return true;
      }

      return false;
    }
  };

  class MyCalendar *my_calendar;
};

TEST_F(q729, sample_input01) {
  my_calendar = new MyCalendar();
  EXPECT_EQ(my_calendar->book(10, 20), true);
  EXPECT_EQ(my_calendar->book(15, 25), false);
  EXPECT_EQ(my_calendar->book(20, 30), true);
  delete my_calendar;
}