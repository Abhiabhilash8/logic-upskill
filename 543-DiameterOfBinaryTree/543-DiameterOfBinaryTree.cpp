// Last updated: 4/5/2026, 11:45:40 AM
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
int maxd=0;
int height(struct TreeNode* root){
    if(root==NULL)
    return 0;
    int x=height(root->left);
    int y=height(root->right);
    maxd=max(maxd,x+y);
    // if(maxd<x+y)
    // maxd=x+y-2;
  
    return 1+max(x,y);
}
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxd;
    }
};