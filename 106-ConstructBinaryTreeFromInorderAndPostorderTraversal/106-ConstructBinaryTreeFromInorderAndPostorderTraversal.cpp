// Last updated: 4/5/2026, 11:47:47 AM
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

    TreeNode* build(vector<int>&inorder,int instart,int inend,vector<int>&postorder,int poststart,int postend,map<int,int>&inmpp){
        if(inend<instart||postend<poststart) return NULL;

        int rootind=inmpp[postorder[postend]];

        TreeNode* root=new TreeNode(postorder[postend]);
        int numsright=inend-rootind;

        root->left=build(inorder,instart,rootind-1,postorder,poststart,postend-numsright-1,inmpp);
        root->right=build(inorder,rootind+1,inend,postorder,postend-numsright,postend-1,inmpp);

        return root;

    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>inmpp;
        for(int i=0;i<inorder.size();i++) inmpp[inorder[i]]=i;
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inmpp);
        
    }
};