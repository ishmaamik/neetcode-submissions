class Solution {
public:
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
	
	vector<vector<int>> closestNodes;
	priority_queue<int, vector<int>, greater<int>> pq;
	map<vector<int>, int> mp;

	for(auto &a: points){
		int distance = a[0]*a[0] + a[1]*a[1];
		pq.push(distance);
		mp.insert({{a[0], a[1]}, distance});
	}

	int allowed= k;

	while(k>=1){
		int closest= pq.top();
		pq.pop();

		cout<<closestNodes.size()<<endl;
		for(auto &m: mp){

			if(m.second==closest && closestNodes.size()<allowed){
				closestNodes.push_back(m.first);
			}
		}

		k--;
	}

	return closestNodes;        
}


};
