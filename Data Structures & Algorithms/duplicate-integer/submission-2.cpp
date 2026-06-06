//a.find(nums[i]) because nums[i] may exist more than once but not
//i
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> set;

       for(int i=0; i<nums.size(); i++){
            if(set.count(nums[i])){
                return true;
            }
            set.insert(nums[i]);
       }
       return false;
    }
};