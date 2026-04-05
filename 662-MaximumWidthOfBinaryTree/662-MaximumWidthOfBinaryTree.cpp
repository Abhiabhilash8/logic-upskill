// Last updated: 4/5/2026, 11:45:31 AM
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
    int widthOfBinaryTree(TreeNode* root) {
        // it is max no of nodes b/w 2 nodes at same level(including imaginary roots)
        // we can do a level order traversal for it 
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        int ans=0;
        q.push({root,0});
        while(!q.empty()){
            int minw=q.front().second;
            int size=q.size();
            long long first,last;
            for(int i=0;i<size;i++){
                long long curid=q.front().second-minw;
                TreeNode* temp=q.front().first;
                q.pop();
                if(i==0) first=curid;
                if(i==size-1) last=curid;
                if(temp->left) q.push({temp->left,curid*2+1});
                if(temp->right) q.push({temp->right,curid*2+2});

            }
            ans=max(ans,int(last-first+1));
        }
        return ans;
    }
};