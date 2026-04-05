// Last updated: 4/5/2026, 11:45:55 AM
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
    TreeNode* insuc(TreeNode* root){
        if(root->left==NULL){
            return root;
        }
        else
            return insuc(root->left);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        else if(key<root->val){
            root->left=deleteNode(root->left,key);
        }
        else if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        else{
            if(root->left==NULL){
                return root->right;
            }
            else if(root->right==NULL){
                return root->left;
            }
            else{
                struct TreeNode *temp=insuc(root->right);
                root->val=temp->val;
                //insuc(root->right)->val=key;
                root->right=deleteNode(root->right,temp->val);
                return root;
            }
        }
        return root;
    }
};