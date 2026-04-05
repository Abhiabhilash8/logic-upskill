// Last updated: 4/5/2026, 11:44:35 AM
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
void in(TreeNode* node,vector<int>&v){
    if(!node) return;

    in(node->left,v);
    v.push_back(node->val);

    in(node->right,v);
}

TreeNode* insert(int l,int r,vector<int>&v){
    if(l>r) return NULL;
    int m=l+(r-l)/2;
    TreeNode* root= new TreeNode(v[m]);

    root->left=insert(l,m-1,v);
    root->right=insert(m+1,r,v);
    return root;
}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        in(root,v);
        TreeNode* r;
            r=insert(0,v.size()-1,v);

        return r;
    }
};