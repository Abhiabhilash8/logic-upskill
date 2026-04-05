// Last updated: 4/5/2026, 11:47:55 AM
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
    bool help(TreeNode* left,TreeNode* right){
        if(left==NULL&&right==NULL) return true;
        if(left&&right==NULL||right&&left==NULL) return false;

        if(left->val!=right->val) return false;

        bool x=help(left->left,right->right);
        bool y=help(left->right,right->left);

        return x&&y;
    }
    bool isSymmetric(TreeNode* root) {
        // level order trav and check for symmetry at every level(iterative approach)
        if(root==NULL) return true;
        return help(root,root);
    }
};