// Last updated: 4/5/2026, 11:47:53 AM
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        int f=0;
        // f->0 for l->r 1 for r->l
        queue<TreeNode*>q;
         if(root) q.push(root);
        while(!q.empty()){
            vector<int>temp;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
                if(f==1) reverse(temp.begin(),temp.end());

                ans.push_back(temp);
                if(f==1) f=0;

                else f=1;
        }
        return ans;
    }
};