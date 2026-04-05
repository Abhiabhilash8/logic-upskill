// Last updated: 4/5/2026, 11:47:46 AM
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
int heightdiff(TreeNode* root,int &f){
    if(!root) return 0; 
    int left=1+heightdiff(root->left,f);
    int right=1+heightdiff(root->right,f);
    
    if(abs(left-right)>1) f=1;
    return max(left,right);

}
    bool isBalanced(TreeNode* root) {
        int f=0;
        heightdiff(root,f);
        if(f==1) return false;
        else return true;
    }
};