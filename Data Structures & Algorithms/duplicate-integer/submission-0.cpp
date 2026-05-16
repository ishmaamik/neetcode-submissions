//a.find(nums[i]) because nums[i] may exist more than once but not
//i
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> a;
        for(int i=0; i<nums.size(); i++){
            if(a.find(nums[i])!= a.end()){
                return true;
            }
            else{
                a.insert({nums[i], i});
                
            }
        }
        return false;
    }
};