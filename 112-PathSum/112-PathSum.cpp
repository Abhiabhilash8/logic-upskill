// Last updated: 4/5/2026, 11:47:45 AM
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
    bool hasPathSum(TreeNode* root, int targetsum) {
        if(root==NULL)  return 0;
        else if(root->left==NULL&&root->right==NULL&&root->val==targetsum)   return 1;
        else{
            
            return hasPathSum(root->left,targetsum-root->val)+hasPathSum(root->right,targetsum-root->val);
        }
        return 0;
    }
};