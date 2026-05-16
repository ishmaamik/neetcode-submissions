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
int goodNodes(TreeNode* root) {

	if(root==NULL) return 0;

	int count=0;

	stack<pair<TreeNode*, int>> s;
	s.push({root, root->val});

	while(!s.empty()){
		TreeNode* node= s.top().first;
		int maxSoFar= s.top().second;

		s.pop();

		if(node->val>= maxSoFar) count++;

		int highest= max(maxSoFar, node->val);

		if(node->left) s.push({node->left, highest});

		if(node->right) s.push({node->right, highest});

	}

	return count;
}
                          };
