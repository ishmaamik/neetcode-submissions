/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int DistanceFromRoot(TreeNode *root, map<TreeNode*,TreeNode*>& parent){
	if(root==NULL) return 0;

	int level=0;
	while(parent[root]!=NULL){
		root= parent[root];
		level++;
	}

	return level;
}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
	map<TreeNode*, TreeNode*> mp;
	queue<TreeNode*> r;
	r.push(root);

	mp[root]=NULL;
	while(!r.empty()){
		int size= r.size();

		for(int i=0; i<size; i++){
			TreeNode* top= r.front();
			r.pop();

			if(top->left) {
				r.push(top->left);
				mp[top->left]= top;
			}

			if(top->right){
				r.push(top->right);
				mp[top->right]= top;
			}

		}
	}



	TreeNode* i= p;
	TreeNode* j= q;

	int levelP= DistanceFromRoot(i, mp);
	int levelQ= DistanceFromRoot(j, mp);
	cout<<levelP<<" "<<levelQ<<endl;

	TreeNode* longer= (levelP>levelQ) ? i : j;
	TreeNode* shorter= (levelP>levelQ) ? j : i;

	for(int k=0; k<abs(levelP-levelQ); k++){
		longer= mp[longer];
	}

	while(longer!=shorter){
		longer= mp[longer];
		shorter= mp[shorter];
	}

	return longer;
}

};
