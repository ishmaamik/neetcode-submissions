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
    vector<int> InOrderTraverse(TreeNode* root){
	vector<int> nodes;
	nodes.push_back(-1);
	stack<TreeNode*> s;
	TreeNode* curr= root;

	while(curr!=NULL || !s.empty()){
		while(curr!=NULL){
			s.push(curr);
			curr= curr->left;
		}

		curr= s.top();
		s.pop();

		nodes.push_back(curr->val);

		curr= curr->right;
	}

	return nodes;
}

int kthSmallest(TreeNode* root, int k) {
      vector<int> n= InOrderTraverse(root);

      return n[k];
}

};
