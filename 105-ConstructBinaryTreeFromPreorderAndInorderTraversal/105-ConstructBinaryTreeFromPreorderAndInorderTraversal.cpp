// Last updated: 4/5/2026, 11:47:49 AM
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

    TreeNode* build(vector<int>&inorder,int instart,int inend,vector<int>&preorder,int prestart,int preend,map<int,int>&inmpp){
        if(inend<instart||preend<prestart) return  NULL;

        TreeNode* root=new TreeNode(preorder[prestart]);
        int inroot=inmpp[root->val];
        int numsleft=inroot-instart;

        root->left=build(inorder,instart,inroot-1,preorder,prestart+1,prestart+numsleft,inmpp);
        root->right=build(inorder,inroot+1,inend,preorder,prestart+numsleft+1,preend,inmpp);

        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inmpp;
        for(int i=0;i<inorder.size();i++){
            inmpp[inorder[i]]=i;
        }

        return build(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,inmpp);
        
    }
};