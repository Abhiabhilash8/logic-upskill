// Last updated: 4/5/2026, 11:44:39 AM
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
 int s(TreeNode* root,int x){
    if(!root) return 0;
    x=(x<<1)|(root->val);
    if((!root->left && !root->right)) return x;

    return s(root->left,x)+s(root->right,x);

 }


class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {


        return s(root,0);
    }
};