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

    int PathSum(TreeNode* root, int& globalSum){
        if(root==NULL) return 0;
        int LeftSum= max(0,PathSum(root->left, globalSum));
        int RightSum= max(0, PathSum(root->right, globalSum));

        int CurrValue= root->val;
        int CurrSum= CurrValue + LeftSum + RightSum;

        if(CurrSum>globalSum){
            globalSum= CurrSum;
        }

        return CurrValue + max(LeftSum,RightSum);
        //Return extendable paths only to parent
        //Not paths that use both the subtrees and the root
    }

    int maxPathSum(TreeNode* root) {
        int globalSum= INT_MIN;
        //To allow negative values as well!
        PathSum(root, globalSum);
        return globalSum;
    }
};
