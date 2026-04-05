// Last updated: 4/5/2026, 11:45:36 AM
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
    bool trav(TreeNode* root, TreeNode* subRoot,int key){
        int x=0,y=0;
        if(root==NULL)
        return false;
        else if(root->val==key){
            if(isSameTree(root,subRoot))
            return true;
        }
        
            x=trav(root->left,subRoot,key);
           y=trav(root->right,subRoot,key);
        
        return x||y;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return trav(root,subRoot,subRoot->val);
    }
};