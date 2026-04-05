// Last updated: 4/5/2026, 11:44:50 AM
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int horizontal,vertical;
        map<int,map<int,multiset<int>>>nodes;
        // it holds map<verticals,multiset<horizontals(level),values(sorted if common)>>>
        queue<pair<TreeNode*,pair<int,int>>>q;
        // it holds queue<pair<node,pair<verticals,horizontals>>>
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int vertical=temp.second.first;
            int horizontal=temp.second.second;
            nodes[vertical][horizontal].insert(temp.first->val);
            if(temp.first->left){
                q.push({temp.first->left,{vertical-1,horizontal+1}});
            }
            if(temp.first->right){
                q.push({temp.first->right,{vertical+1,horizontal+1}});
            }

        }
        // we stored ans in the form of nodes (mp) with vertical and horizontal numbering
        // converting it into vector of vectors
        vector<vector<int>>ans;
        for(auto& it:nodes){
        vector<int>tempans;
            for(auto q:it.second){
                tempans.insert(tempans.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(tempans);
        }
        return ans;
    }
};