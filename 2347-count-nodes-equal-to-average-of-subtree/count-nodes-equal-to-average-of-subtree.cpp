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
    int ans = 0;
    pair<int , int> f(TreeNode* root){
        if(!root) return {0 , 0};
        pair<int , int> lt = f(root -> left) , rt = f(root -> right);
        int s = lt.first +  rt.first + root -> val;
        int n = lt.second + rt.second + 1;
        if(s / n == root -> val) ans++;
        return {s , n};
    }
    int averageOfSubtree(TreeNode* root) {
        f(root);
        return ans;
    }
};