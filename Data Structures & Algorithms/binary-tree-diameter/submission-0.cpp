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

    int maxDepth(TreeNode *root, unordered_map<int, int> &m){
	if(root==NULL) return 0;

	int leftHeight= maxDepth(root->left, m);
	int rightHeight= maxDepth(root->right, m);

	m.insert({root->val, leftHeight+rightHeight});

	return 1+ max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
      unordered_map<int,int> m;
	maxDepth(root, m);

	int diameter=0;

	for(auto &p: m){
		if(p.second>diameter){
			diameter= p.second;
		}
	}
	return diameter;  
    }
};
