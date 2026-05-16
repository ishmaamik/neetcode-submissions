class Solution {
public:
    
int findKthLargest(vector<int>& nums, int k) {

	priority_queue<int, vector<int>,greater<int>> pq;

	for(auto &a: nums){
		if(pq.size()<k)
		{
			pq.push(a);
		}
		else if(a>pq.top()){
			pq.pop();
			pq.push(a);
		}
	}

	return pq.top();        
}
};
