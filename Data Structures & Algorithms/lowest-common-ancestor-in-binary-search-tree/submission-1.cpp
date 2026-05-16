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
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
	map<TreeNode*, TreeNode*> mp;
	queue<TreeNode*> r;
	unordered_set<TreeNode*> c;
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

	while(i!=NULL){
		c.insert(i);
		i= mp[i];
	}

	while(c.find(j)==c.end()){
		j=mp[j];
	}
	return j;
}


};
