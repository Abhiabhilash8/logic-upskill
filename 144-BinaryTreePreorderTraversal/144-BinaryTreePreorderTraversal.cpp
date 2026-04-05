// Last updated: 4/5/2026, 11:47:25 AM
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
vector<int>ans;
       void preorder(struct TreeNode* temp){
            if(temp==NULL){
                return;
            }
            ans.push_back(temp->val);
            preorder(temp->left);
            preorder(temp->right);
            
            
        }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ans;
    }    
       
};