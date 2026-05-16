class Solution {
public:
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
	vector<vector<int>> closestNodes;
	auto compare= [](vector<int> &a, vector<int>&b){
		return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
	};

	priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);

	for(auto &s: points){
		int c= s[0];
		int d= s[1];

		if(pq.size()<k){
			pq.push(s);
		}
		else if((c*c + d*d) < pq.top()[0]* pq.top()[0] + pq.top()[1]*pq.top()[1]){
			pq.pop();
			pq.push(s);
		}
	}

	while(!pq.empty()){
		closestNodes.push_back(pq.top());
		pq.pop();
	}
	return closestNodes;        
}

};
