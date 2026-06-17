class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low= 0;
        int high= numbers.size()-1;

        //Using mid here skips some valid pairs
        
        while(low<=high){
            int mid= (low+high)/2;
            if(numbers[low]+numbers[high]<target){
                low++;
            }
            else if(numbers[low]+numbers[high]>target){
                high--;
            }
            else{
                return {low+1, high+1};
            }
        }

        return {};
    }
};