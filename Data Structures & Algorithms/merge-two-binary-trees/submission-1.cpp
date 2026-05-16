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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

	if(!root1) return root2;
	if(!root2) return root1;

	queue<pair<TreeNode*, TreeNode*>> q;

	q.push({root1, root2});

	while(!q.empty()){
		TreeNode* n1= q.front().first;
		TreeNode* n2= q.front().second;
		q.pop();

		n1->val+= n2->val;

		if(n1->left && n2->left){
			q.push({n1->left, n2->left});
		}
		else if(!n1->left && n2->left){
			n1->left= n2->left; 
		}

		if(n1->right && n2->right){
			q.push({n1->right, n2->right});
		}
		else if(!n1->right && n2->right){
			n1->right= n2->right;
		}
	}
    return root1;
}
};