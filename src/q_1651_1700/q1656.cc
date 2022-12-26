#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1656.
 *       Design an Ordered Stream
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   There is a stream of ‘n’  ‘(idKey, value)’ pairs arriving in an
 *   “arbitrary” order, where ‘idKey’ is an integer between ‘1’ and ‘n’ and
 *   ‘value’ is a string. No two pairs have the same ‘id’
 *   Design a stream that returns the values in “increasing order of their
 *   IDs” by returning a “chunk” (list) of values after each insertion. The
 *   concatenation of all the “chunks” should result in a list of the
 *   sorted
 *   Implement the ‘OrderedStream’
 *       -  ‘OrderedStream(int n)’ Constructs the stream to take ‘n’
 *       -  ‘String[] insert(int idKey, String value)’ Inserts the pair
 *   ‘(idKey, value)’ into the stream, then returns the “largest possible
 *   chunk” of currently inserted values that appear next in the order.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ n ≤ 1000’
 *   • ‘1 ≤ id ≤ n’
 *   • ‘value.length = 5’
 *   • ‘value’ consists only of lowercase letters.
 *   • Each call to ‘insert’ will have a unique ‘id.’
 *   • Exactly ‘n’ calls will be made to ‘insert’ .
 *
 */

struct q1656 : public ::testing::Test {
  // Leetcode answer here
  class OrderedStream {
  private:
    int            idx_;
    vector<string> data_;

  public:
    OrderedStream(int n) {
      idx_ = 0;
      data_.clear();
      data_.resize(n + 1, "");
    }

    vector<string> insert(int idKey, string value) {
      auto res         = vector<string>();
      data_[idKey - 1] = value;

      while (!data_[idx_].empty()) {
        res.emplace_back(data_[idx_++]);
      }

      return res;
    }
  };

  class OrderedStream *ordered_stream;
};

TEST_F(q1656, sample_input01) {
  ordered_stream = new OrderedStream(5);
  auto actual    = vector<string>();
  EXPECT_EQ(ordered_stream->insert(3, "ccccc"), actual);
  actual.emplace_back("aaaaa");
  EXPECT_EQ(ordered_stream->insert(1, "aaaaa"), actual);
  actual.clear();
  actual.emplace_back("bbbbb");
  actual.emplace_back("ccccc");
  EXPECT_EQ(ordered_stream->insert(2, "bbbbb"), actual);
  actual.clear();
  EXPECT_EQ(ordered_stream->insert(5, "eeeee"), actual);
  actual.emplace_back("ddddd");
  actual.emplace_back("eeeee");
  EXPECT_EQ(ordered_stream->insert(4, "ddddd"), actual);
}
