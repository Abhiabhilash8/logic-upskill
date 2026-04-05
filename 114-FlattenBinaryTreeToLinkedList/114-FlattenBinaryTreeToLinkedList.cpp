// Last updated: 4/5/2026, 11:47:43 AM
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

    void build(TreeNode* root,TreeNode* &prev){
        if(root==NULL) return;
        build(root->right,prev);
        build(root->left,prev);
        root->left=NULL;
        root->right=prev;
        prev=root;
    }
    void flatten(TreeNode* root) {
        TreeNode* prev=NULL;
        build(root,prev);
    }
};