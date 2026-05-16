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
    TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder, int& idx, int inStart, int inEnd){

	if (inStart > inEnd) return nullptr;

	TreeNode* root= new TreeNode(preorder[idx]);

	int divisorIdx= inStart;

	for(int i=inStart; i<=inEnd; i++){
		 if(inorder[i]==root->val) 
		 	{
		 		divisorIdx=i;
		 		break;
		 	}
	}

	idx++;

	root->left= buildSubTree(preorder, inorder, idx, inStart, divisorIdx-1);
	root->right= buildSubTree(preorder, inorder,idx, divisorIdx+1, inEnd);

	return root;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	int idx=0;
		
		if(preorder.empty()) return nullptr;

		return buildSubTree(preorder, inorder, idx, 0, preorder.size()-1);
}
};
