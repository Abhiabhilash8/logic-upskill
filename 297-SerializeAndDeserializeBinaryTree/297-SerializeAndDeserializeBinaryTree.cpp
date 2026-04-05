// Last updated: 4/5/2026, 11:46:21 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {  
        if(root==NULL) return "";
        queue<TreeNode*>q;
        string ans="";
        q.push(root);
        while(!q.empty()){
            TreeNode* curnode=q.front();
            q.pop();
            if(curnode==NULL) ans.append("#,");

            else
            ans.append(to_string(curnode->val)+',');

            if(curnode!=NULL){
                q.push(curnode->left);
                q.push(curnode->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);   
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            getline(s,str,',');
            TreeNode* cur=q.front();
            q.pop();

            if(str=="#") cur->left= NULL;
            else{
                cur->left=new TreeNode(stoi(str));
                q.push(cur->left);
            }
                getline(s,str,',');

            if(str=="#") cur->right= NULL;
            else{
                cur->right=new TreeNode(stoi(str));
                q.push(cur->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));