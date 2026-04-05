// Last updated: 4/5/2026, 11:44:55 AM
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
   
    int rangeSumBST(TreeNode* root, int low, int high) {
         int sum=0;
        if(root==NULL){
            return 0;
        }
        else if(root->val>=low&&root->val<=high){
            sum= root->val;
        }
        else{
            sum= 0;
        }
        sum+= rangeSumBST(root->left,low,high);
        sum+=rangeSumBST(root->right,low,high);
            return sum;
    }
};