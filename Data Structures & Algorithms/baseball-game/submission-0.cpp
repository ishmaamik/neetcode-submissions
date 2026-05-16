class Solution {
public:
    vector<int> ans;

    int calPoints(vector<string>& operations) {
        if(operations.size()==0) return 0;

        for(auto &a : operations){
            handleOperations(a, ans);
        }

        int sum=0;

        for(auto &a: ans){
            sum+= a;    
        }

        return sum;    
    }

    void handleOperations(string s, vector<int>& arr){
        int sz= arr.size();

        if(s=="C"){
            arr.erase(arr.end()-1);
        }
        else if(s=="D"){
            arr.push_back(arr[sz-1] * 2);
        }
        else if(s=="+"){
            arr.push_back(arr[sz-1] + arr[sz-2]);
        }
        else{
            arr.push_back(stoi(s));
        }
    }
};