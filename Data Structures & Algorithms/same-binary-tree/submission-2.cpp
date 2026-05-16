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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector <string> nodeListP;
        vector <string> nodeListQ;
        stack<TreeNode*> s;
        s.push(p);
       while(!s.empty()){
        TreeNode* v= s.top();
        s.pop();

        if(v==NULL){
            nodeListP.push_back("#");
            continue;
        }
        nodeListP.push_back(to_string(v->val));
        s.push(v->left);
        s.push(v->right);
       }

        s.push(q);
       while(!s.empty()){
        TreeNode* v= s.top();
        s.pop();

        if(v==NULL){
            nodeListQ.push_back("#");
            continue;
        }
        nodeListQ.push_back(to_string(v->val));
        s.push(v->left);
        s.push(v->right);
       }
       
       return(nodeListP==nodeListQ);
}
};
