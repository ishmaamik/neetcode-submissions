class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
	
	priority_queue<int> pq;

	for(auto s: stones){
		pq.push(s);
	}

	while(pq.size()>1){
		int highest= pq.top();
		pq.pop();
		int secondHighest= pq.top();
		pq.pop();

		if(highest>secondHighest){
			pq.push(abs(highest-secondHighest));
		}        
		else{
			continue;
		}
	}
	return pq.empty() ? 0 : pq.top();
}

};
