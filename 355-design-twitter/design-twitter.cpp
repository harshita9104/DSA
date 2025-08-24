class Twitter {
public:
long long time;
unordered_map<int,vector<pair<int, int>>> tweets;//key is userid , value is list of pair of time and tweetid
unordered_map<int, set<int>> following;//key is user id and value is set of users this user followes
    Twitter() {
        time =0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int, int>> maxheap;
        for(auto it: tweets[userId]){
            //we are iterating over the list of tweets the userId has made
            maxheap.push(it);
        }
        //now we need to iterate over the tweets of the users this userId followes
        for(int follow : following[userId]){
            for(auto it: tweets[follow]){
                maxheap.push(it);
            }
        }
        while(!maxheap.empty() && ans.size()< 10){
            int tweet = maxheap.top().second;
            ans.push_back(tweet);
            maxheap.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */