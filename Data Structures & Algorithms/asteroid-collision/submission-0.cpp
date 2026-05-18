class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<vector<int>> st;
        vector<int> ans;

        for(auto &a: asteroids){
            if(a>0){
                if(st.size()==0){
                    st.push_back({a, INT_MIN});
                }
                else{
                    st.push_back({a, st.back()[0]}); 
                }
            }
            else if(a<0){
                if(st.size()==0){
                    st.push_back({a, INT_MIN});
                    continue;
                }

                while(!st.empty() && st.back()[0]< abs(a) && st.back()[0]>0){
                    st.pop_back();
                }

                if(!st.empty() && st.back()[0]== -a){
                    st.pop_back();
                }
                else if(st.size()==0 || st.back()[0]<0){
                    st.push_back({a, !st.empty() ? st.back()[0] : INT_MIN});
                }
            }
        }

        for(auto &a: st){
            ans.push_back(a[0]);
        }

        return ans;
    }
};