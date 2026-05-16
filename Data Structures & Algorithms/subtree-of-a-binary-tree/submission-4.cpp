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
   vector<string> PreOrder(TreeNode* root){
	stack<TreeNode*> s;
	vector<string> nodes;
	s.push(root);

	while(!s.empty()){
		TreeNode* curr= s.top();
		s.pop();

		if(curr) nodes.push_back(to_string(curr->val));
		else 
			{
				nodes.push_back("#");
				continue;
			}
		
		//Pushing null children is mandatory too now
		//otherwise say 2,4,5 (parent, left, right) exists 
		//but 4 is right of 2, 5 is right
		//of 2's root it will show that it is subtree
		 s.push(curr->right);
		 s.push(curr->left);
	}
	return nodes;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
	if(!subRoot) return true;

	if(!root) return false;

	vector<string> rootVec= PreOrder(root);
	vector<string> subRootVec= PreOrder(subRoot);
	//sub root (j) iterates on and on
	//but there has to be some way to iterate i
	//but i++ will uncontrollably increase
	//and cause null pointer issue as i>rootVec.size()

	//rootVec.size()-subRootVec.size() suppose i is 9 long
	//but subroot is say 3 long, after that when i comes to
	//8 (8+3) becomes 11 out of bounds

	for(int i=0; i<=rootVec.size()-subRootVec.size();i++){
		
		//to reset on every iteration we
		//declare it here, we could declare above but reassign
		//here again
		bool match=true;	
		
		for(int j=0; j<subRootVec.size(); j++){
			if(rootVec[i+j]!= subRootVec[j]){
				match= false;
				break;
			}
		}
		if(match) return true;
	}

	return false;         
}

};
