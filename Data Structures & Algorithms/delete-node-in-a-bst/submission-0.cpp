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
    TreeNode* findLastRightChild(TreeNode* root){
	if(root->right==NULL) return root;
	
	return findLastRightChild(root->right);
}

TreeNode* helper(TreeNode* root){
	if(root->left==NULL) return root->right;

	else if(root->right==NULL) return root->left;

	TreeNode* rightChild= findLastRightChild(root->left);
	rightChild->right= root->right;
	return root->left; 
}

TreeNode* deleteNode(TreeNode* root, int key) {

	if(!root) return root;

	if(root->val== key) return helper(root);

     TreeNode* curr= root;
     TreeNode* prev= NULL;

     while(curr && curr->val != key){
     	prev= curr;
     	curr= key > curr->val ? curr->right : curr->left;
     }

     if (!curr) return root;

     if(key>prev->val)	prev->right= helper(curr);

     else prev->left= helper(curr);

     return root;
     
}

};