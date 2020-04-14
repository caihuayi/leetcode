#include <list>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {

    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        is_newUser(userId);
        msg_list.push_back(new pair<int, int>(userId, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        is_newUser(userId);
        set<int>* following_set = following_map[userId];
        vector<int> news_vector;
        list<pair<int, int>*>::reverse_iterator riter = msg_list.rbegin();
        for (; riter != msg_list.rend() && news_vector.size() < 10; ++riter)
        {
            if (following_set->find((*riter)->first) != following_set->end())
                news_vector.push_back((*riter)->second);
        }

        return news_vector;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        is_newUser(followerId);
        following_map[followerId]->insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        is_newUser(followerId);
        if (followerId != followeeId)
            following_map[followerId]->erase(followeeId);
    }
private:
    bool is_newUser(int id)
    {
        map<int, set<int>*>::iterator iter = following_map.find(id);
        if (iter == following_map.end())
        {
            set<int> *following_set = new set<int>();
            following_set->insert(id);
            following_map.insert(pair<int, set<int>*>(id, following_set));
            return true;
        }
        return false;
    }

private:
    map<int, set<int>*> following_map;
    list<pair<int, int>*> msg_list;
};

int main()
{
    Twitter* twitter = new Twitter();
    twitter->postTweet(1, 5);
    twitter->getNewsFeed(1);
    twitter->follow(1,2);
    twitter->postTweet(2, 6);
    twitter->getNewsFeed(1);
    twitter->unfollow(1, 2);
    twitter->getNewsFeed(1);

    return 0;
}
/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */