// Last updated: 4/5/2026, 11:47:08 AM
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>ans;
        if(root==NULL) return ans;
        q.push(root);
        while(!q.empty()){
            int size=q.size(),x;
            for(int i=0;i<size;i++){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
                x=temp->val;
            }
            ans.push_back(x);
        }
        return ans;
    }
};