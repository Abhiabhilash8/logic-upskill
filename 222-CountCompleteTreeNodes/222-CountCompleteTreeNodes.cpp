// Last updated: 4/5/2026, 11:46:44 AM
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

    int lefth(TreeNode* root){
        if(root==NULL) return 0;
        else return 1+lefth(root->left);
    }

    int righth(TreeNode* root){
        if(root==NULL) return 0;
        else return 1+righth(root->right);
    }

    int nodes(TreeNode* root){
        if(root==NULL) return 0;
        int lh=0,rh=0;

        if(root->left) lh=lefth(root->left);
        if(root->right) rh=righth(root->right);
        if(lh==rh) return pow(2,lh+1)-1;
        else return 1+nodes(root->left)+nodes(root->right);
    }


    int countNodes(TreeNode* root) {
        return nodes(root);
    }
};