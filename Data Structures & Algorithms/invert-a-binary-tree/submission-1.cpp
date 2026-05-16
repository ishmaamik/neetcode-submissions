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
    TreeNode* invertTree(TreeNode* root) {
	if (!root) return nullptr;
	stack<TreeNode*> s;

	//We are not changing values, we are doing
	//it by reference so changing one children changes its
	//grandchildren by default too
	//e.g. 
	//   1 
	//  / \ 
	//  2 3 
	// / \ 
	// 4 5
	//becomes
	//   1 
	//  / \ 
	//  3  2 
	// 	  / \ 
	//   4   5 

	s.push(root);

	while(!s.empty()){
		
		//	2
		// / \
		//1	  3
		//Now Inorder expects 1,2,3 but when coming to 2 from 1
		//it changed 3 and 1's pos, now the curr->right goes
		//and sees 1 again, confused.
		// while(curr!=NULL){
		// 	s.push(curr);
		// 	curr= curr->right;
		// }

		TreeNode* curr= s.top();
		s.pop();

		//Even if null pointer they must be changed
		// if(curr->left || curr->right)
		// {

		TreeNode* temp= curr->right;
		curr->right= curr->left;
		curr->left= temp;
		if(curr->right) s.push(curr->right);
		if(curr->left) s.push(curr->left);

	}

	return root;        
}

};
