// Last updated: 4/5/2026, 11:45:39 AM
class Solution {
public:

    void dfs(int j,vector<vector<int>>&mat,vector<int>&vis){
        for(int i=0;i<mat.size();i++){
            if(vis[i] || !mat[j][i]) continue;

            vis[i]=1;
            dfs(i,mat,vis);
        }
    }

    int findCircleNum(vector<vector<int>>& mat) {
        int c=0;
        vector<int>vis(mat.size(),0);

        for(int i=0;i<mat.size();i++){
            if(vis[i] || !mat[i][i]) continue;

            vis[i]=1;
            dfs(i,mat,vis);
            c++;
        }

        return c;
    }
};