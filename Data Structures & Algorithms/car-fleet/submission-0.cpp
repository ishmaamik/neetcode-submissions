class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> track;

        for(int i=0; i<position.size(); i++){
            double time= (double) (target- position[i])/speed[i]; 
            track.push_back({position[i], time});
        }

        sort(track.begin(), track.end(), greater<>());
        //vector sort is more memory efficient and more cpu friendly than
        //BST Map due to lower overhead
    
        //Suppose A is at a position closer to target, B is at a farther
        //position but still has faster times so it catches up to A
        //However if we started from B to A we wouldn't have known if
        //B caught up to A, so we go descending position-wise so
        //[-position[i]]    
            
        int res=0; double cur=0;

        for(auto a: track){
            if(a.second> cur){
                cur= a.second;
                res++;
            }
        }

        return res;
    }
};