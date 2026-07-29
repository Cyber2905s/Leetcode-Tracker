class Twitter {
    int time;
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> following;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        if(tweets.find(userId) != tweets.end()){
            for(const auto& tweet: tweets[userId]){
                pq.push(tweet);
            }
        }
        if(following.find(userId) != following.end()){
            for(int followeeId : following[userId]){
                if(tweets.find(followeeId) != tweets.end()){
                    for(const auto& tweet: tweets[followeeId]){
                        pq.push(tweet);
                    }
                }
            }
        }
        vector<int> newsFeed;
        int count =0;
        while(!pq.empty() && count<10){
            newsFeed.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following.find(followerId) != following.end()){
            following[followerId].erase(followeeId);
        }
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
