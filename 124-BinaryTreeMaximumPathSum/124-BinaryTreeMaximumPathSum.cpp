// Last updated: 4/5/2026, 11:47:38 AM
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
    int pathsum(TreeNode* root,int &maxs){
        if(!root) return 0;
        int leftsum=max(0,pathsum(root->left,maxs));
        int rightsum=max(0,pathsum(root->right,maxs));


        maxs=max(maxs,leftsum+rightsum+root->val);
        return root->val + max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxs=INT_MIN;

        pathsum(root,maxs);
        return maxs;
    }
};