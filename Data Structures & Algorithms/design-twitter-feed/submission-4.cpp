struct Compare{
     bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second; // min-heap by timestamp
    }
};

class Twitter {
public:
    
    unordered_map<int, vector<pair<int,int>>> myPosts;
    unordered_map<int, multiset<int>> followers;
    unordered_map<int, multiset<int>> following;
    int timeCount;
    
    Twitter() {
        this->timeCount=0;
    }
    
    void postTweet(int userId, int tweetId) {
        myPosts[userId].push_back({tweetId, timeCount});
        timeCount++;
    }
    
    vector<int> getNewsFeed(int userId) {
        
        unordered_map<int, priority_queue<pair<int,int>, vector<pair<int,int>>, Compare>> mp;
        unordered_set<int> seen;

        for(auto& a: myPosts[userId]){
            
            if(seen.count(a.second)) continue;
            seen.insert(a.second);
            
            if(mp[userId].size()<10)
                    mp[userId].push(a);
            
            else if (a.second > mp[userId].top().second)
            {
                mp[userId].pop();
                mp[userId].push(a);
            }

        }
        

        if(following[userId].size()>0){
            
            for(auto &a: following[userId]){
                for(auto &b: myPosts[a]){
                    
                    if(seen.count(b.second)) continue;
                    seen.insert(b.second);

                    if(mp[userId].size()<10)
                        mp[userId].push(b);
                    else if (b.second > mp[userId].top().second)
                        {
                            mp[userId].pop();
                            mp[userId].push(b);
                        }
                }
            }

        }



        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> temp= mp[userId];

        vector<int> posts;
        while(!mp[userId].empty()){
            posts.insert(posts.begin(), mp[userId].top().first);
            mp[userId].pop();
        }

        for(int i=0; i<posts.size(); i++){
            cout<<posts[i]<<" ";
        }
        cout<<endl;
        return posts;
    }
    
    void follow(int followerId, int followeeId) {
            following[followerId].insert(followeeId);
            followers[followeeId].insert(followerId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
            following[followerId].erase(followeeId);
            followers[followeeId].erase(followerId);
    }
};
