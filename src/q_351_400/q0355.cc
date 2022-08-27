#include <gtest/gtest.h>
#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 355.
 *      Design Twitter
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Design a simplified version of Twitter where users can post tweets,
 *   follow/unfollow another user, and is able to see the ‘10’ most recent
 *   tweets in the user's news
 *   Implement the ‘Twitter’
 *       -  ‘Twitter()’ Initializes your twitter
 *       -  ‘void postTweet(int userId, int tweetId)’ Composes a new tweet
 *   with ID ‘tweetId’ by the user ‘userId’ . Each call to this function
 *   will be made with a unique ‘tweetId’
 *       -  ‘List<Integer> getNewsFeed(int userId)’ Retrieves the ‘10’ most
 *   recent tweet IDs in the user's news feed. Each item in the news feed
 *   must be posted by users who the user followed or by the user themself.
 *   Tweets must be “ordered from most recent to least recent”
 *       -  ‘void follow(int followerId, int followeeId)’ The user with ID
 *   ‘followerId’ started following the user with ID ‘followeeId’
 *       -  ‘void unfollow(int followerId, int followeeId)’ The user with
 *   ID ‘followerId’ started unfollowing the user with ID ‘followeeId’ .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ userId, followerId, followeeId ≤ 500’
 *   • ‘0 ≤ tweetId ≤ 10⁴’
 *   • All the tweets have “unique” IDs.
 *   • At most ‘3 × 10⁴’ calls will be made to ‘postTweet’ , ‘getNewsFeed’ ,
 * ‘follow’ , and ‘unfollow’ .
 *
 */

struct q355 : public ::testing::Test {
  // Leetcode answer here
  class Twitter {
  private:
    int                                        timestamp;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, set<int>>               follows;

  public:
    Twitter() : timestamp{0} {}

    void postTweet(int userId, int tweetId) {
      tweets[userId].emplace_back(++timestamp, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
      /// init
      follows[userId].emplace(userId);
      vector<vector<pair<int, int>>::reverse_iterator> its;
      vector<int>                                      res;
      for (auto x : follows[userId]) {
        its.emplace_back(tweets[x].rbegin());
      }

      while (res.size() < 10) {
        vector<pair<int, int>>::reverse_iterator *cand = nullptr;
        auto                                      it   = its.begin();

        for (auto x : follows[userId]) {
          if ((*it) != tweets[x].rend()) {
            if (cand == nullptr || (**cand).first < (**it).first) {
              cand = &(*it);
            }
          }
          ++it;
        }

        if (cand == nullptr) {
          break;
        } else {
          res.emplace_back((**cand).second);
          ++(*cand);
        }
      }

      return res;
    }

    void follow(int followerId, int followeeId) {
      follows[followerId].emplace(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
      follows[followerId].erase(followeeId);
    }
  };

  class Twitter *twitter;
};

TEST_F(q355, sample_input01) {
  twitter = new Twitter();
  twitter->postTweet(1, 5);
  EXPECT_EQ(twitter->getNewsFeed(1), vector<int>{5});
  twitter->follow(1, 2);
  twitter->postTweet(2, 6);
  EXPECT_EQ(twitter->getNewsFeed(1), (vector<int>{6, 5}));
  twitter->unfollow(1, 2);
  EXPECT_EQ(twitter->getNewsFeed(1), vector<int>{5});
}