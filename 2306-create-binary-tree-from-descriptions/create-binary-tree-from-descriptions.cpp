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

    void make(TreeNode* root , int node , vector<vector<pair<int,int>>>&adj){
        for(auto it: adj[node]){
            TreeNode* ch = new TreeNode(it.first);
            if(it.second) root->left = ch;
            else root->right= ch;

            make(ch , it.first , adj);
        }

    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        vector<vector<pair<int,int>>>adj(1e5+1);
        set<int>st;
        vector<int>nd;
        for(auto d: descriptions){
            st.insert(d[1]);
            nd.push_back(d[0]);
            nd.push_back(d[1]);
            adj[d[0]].push_back({d[1] , d[2]});
        }

        TreeNode* root = NULL;
        int rv;
        for(int i =0;i<nd.size();i++){
            if(st.find(nd[i]) == st.end()){
                root = new TreeNode(nd[i]);
                rv = nd[i];
                break;
            }
        }

        make(root , rv , adj);

        return root;
    }
};