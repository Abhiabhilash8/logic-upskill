// Last updated: 4/5/2026, 11:44:47 AM
class Solution {
public:

    void pushq(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid,queue<pair<int,int>>&q,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m ||vis[i][j] || grid[i][j]!=1) return;
        else q.push({i,j});
        vis[i][j]=1;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int min=0;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));

        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int n=grid.size(),m=grid[0].size();

        while(q.size()){
            int c=q.size();
            while(c--){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            pushq(i+1,j,vis,grid,q,n,m);
            pushq(i,j+1,vis,grid,q,n,m);
            pushq(i-1,j,vis,grid,q,n,m);
            pushq(i,j-1,vis,grid,q,n,m);
            }

            if(q.size()) min++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1) return -1;
            }
        }

        return min;
        
    }
};