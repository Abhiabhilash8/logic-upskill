// Last updated: 4/5/2026, 11:45:06 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void markparents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parents){
        // we bfs and store
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left){
                parents[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                parents[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // make a unmap to maintain track of parents
        // radially increase upto k and then the nodes will be ans
        

        // parent tracks
        unordered_map<TreeNode*,TreeNode*>parents;
        markparents(root,parents);

        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        while(!q.empty()){
           if(k--==0) break;
           int size=q.size();
           for(int i=0;i<size;i++){
           TreeNode* temp=q.front();
           q.pop();
        //    visited[temp]=true;
           if(temp->left&&!visited[temp->left]){
            visited[temp->left]=true;
           q.push(temp->left);
           } 
           if(temp->right&&!visited[temp->right]){
            visited[temp->right]=true;
            q.push(temp->right);
           }
           if(parents[temp]&&!visited[parents[temp]]){
            visited[parents[temp]]=true;
            q.push(parents[temp]); 
           } 

           }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;


    }
};