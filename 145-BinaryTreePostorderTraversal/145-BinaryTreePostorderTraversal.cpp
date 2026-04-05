// Last updated: 4/5/2026, 11:47:24 AM
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
       void postorder(struct TreeNode* temp){
            if(temp==NULL){
                return;
            }
            postorder(temp->left);
            postorder(temp->right);
            ans.push_back(temp->val);
            
            
        }
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }    
       
};