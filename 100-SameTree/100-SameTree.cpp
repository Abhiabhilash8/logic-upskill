// Last updated: 4/5/2026, 11:47:57 AM
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL)
        return true;

        else if((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL)||(p->val!=q->val)){
            return false;
        }
        bool x= isSameTree(p->left,q->left);
        bool y= isSameTree(p->right,q->right);
        return x&y;
        
    }
};