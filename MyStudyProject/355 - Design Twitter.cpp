//Design a simplified version of Twitter where users can post tweets, follow / unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:
//
//postTweet(userId, tweetId) : Compose a new tweet.
//getNewsFeed(userId) : Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
//follow(followerId, followeeId) : Follower follows a followee.
//unfollow(followerId, followeeId) : Follower unfollows a followee.
//
//Example :
//    Twitter twitter = new Twitter();
//
//// User 1 posts a new tweet (id = 5).
//twitter.postTweet(1, 5);
//
//// User 1's news feed should return a list with 1 tweet id -> [5].
//twitter.getNewsFeed(1);
//
//// User 1 follows user 2.
//twitter.follow(1, 2);
//
//// User 2 posts a new tweet (id = 6).
//twitter.postTweet(2, 6);
//
//// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
//// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
//twitter.getNewsFeed(1);
//
//// User 1 unfollows user 2.
//twitter.unfollow(1, 2);
//
//// User 1's news feed should return a list with 1 tweet id -> [5],
//// since user 1 is no longer following user 2.
//twitter.getNewsFeed(1);

#include "Header.h";

/**
* Your Twitter object will be instantiated and called as such:
* Twitter obj = new Twitter();
* obj.postTweet(userId,tweetId);
* vector<int> param_2 = obj.getNewsFeed(userId);
* obj.follow(followerId,followeeId);
* obj.unfollow(followerId,followeeId);
*/

class Tweet {
public:
    int tid;
    int seqNum;

    Tweet() {

    }

    Tweet(int tweetId, int seq) {
        tid = tweetId;
        seqNum = seq;
    }
};

class User {
public:
    int uid;
    unordered_set<int> followed;
    vector<Tweet> tweets;

    User() {

    }

    User(int userId) {
        uid = userId;
        followed.insert(userId);
    }
    
    void post(Tweet tweet) {
        tweets.push_back(tweet);
    }

    void follow(int userId) {
        followed.insert(userId);
    }

    void unFollow(int userId) {
        followed.erase(userId);
    }
};

class TweetComp {
public:
    bool operator() (const Tweet& x, const Tweet& y) const { return x.seqNum<y.seqNum; }
};

class Twitter {
private:
    unordered_map<int, User> users;
    int seq;

public:
    /** Initialize your data structure here. */
    Twitter() {
        seq = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (users.find(userId) == users.end()) {
            User u(userId);
            users[userId] = u;
        }
        Tweet t(tweetId, seq++);
        users[userId].post(t);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. 
    Each item in the news feed must be posted by users who the user followed or by the user herself. 
    Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        int n = 0;
        vector<int> feeds;
        if (users.find(userId) == users.end()) {
            return feeds;
        }

        unordered_set<int> followed = users[userId].followed;
        priority_queue<Tweet, vector<Tweet>, TweetComp> pq;
        for (int user : followed) {
            if (users.find(user) != users.end()) {
                for (Tweet t : users[user].tweets) {
                    pq.push(t);
                }
            }
        }

        while (!pq.empty() && n++ < 10) {
            feeds.push_back(pq.top().tid);
            pq.pop();
        }

        return feeds;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (users.find(followerId) == users.end()) {
            User follower(followerId);
            users[followerId] = follower;
        }
        users[followerId].follow(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        if (users.find(followerId) != users.end()) {
            users[followerId].unFollow(followeeId);
        }
    }
};

//int main() {
//    Twitter twitter;
//
//    // User 1 posts a new tweet (id = 5).
//    twitter.postTweet(1, 1);
//
//    // User 1's news feed should return a list with 1 tweet id -> [5].
//    twitter.getNewsFeed(1);
//
//    // User 1 follows user 2.
//    twitter.follow(2, 1);
//
//    // User 2 posts a new tweet (id = 6).
//    //twitter.postTweet(2, 6);
//
//    // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
//    // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
//    twitter.getNewsFeed(2);
//
//    // User 1 unfollows user 2.
//    //twitter.unfollow(1, 2);
//
//    //// User 1's news feed should return a list with 1 tweet id -> [5],
//    //// since user 1 is no longer following user 2.
//    //twitter.getNewsFeed(1);
//}