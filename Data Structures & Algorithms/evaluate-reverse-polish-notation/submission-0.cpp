class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> ans;
        
        for(string a: tokens){
            handleOps(a, ans);
        }

        return ans[0];
    }

    void handleOps(string s, vector<int> &ans){
        if(s== "+"){
            int a= ans[ans.size()-2] + ans[ans.size()-1];
            ans.erase(ans.end()-2, ans.end());
            ans.push_back(a);
        }
        else if(s== "-"){
            int a= ans[ans.size()-2] - ans[ans.size()-1];
            ans.erase(ans.end()-2, ans.end());
            ans.push_back(a);
        }
        else if(s== "*"){
            int a= ans[ans.size()-2] * ans[ans.size()-1];
            ans.erase(ans.end()-2, ans.end());
            ans.push_back(a);
        }
        else if(s== "/"){
            int a= ans[ans.size()-2] / ans[ans.size()-1];
            ans.erase(ans.end()-2, ans.end());
            ans.push_back(a);
        }
        else{
            ans.push_back(stoi(s));
        }
    }
};