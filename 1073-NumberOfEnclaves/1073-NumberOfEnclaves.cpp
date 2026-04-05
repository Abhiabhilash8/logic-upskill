// Last updated: 4/5/2026, 11:44:42 AM
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            if(grid[i][0]==1){ q.push({i,0}); vis[i][0]=1; }
            if(grid[i][n-1]==1){ q.push({i,n-1}); vis[i][n-1]=1; }
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]==1){ q.push({0,j}); vis[0][j]=1; }
            if(grid[m-1][j]==1){ q.push({m-1,j}); vis[m-1][j]=1; }
        }

        int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};

        while(!q.empty()){
            auto [x,y]=q.front(); q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k], ny=y+dy[k];
                if(nx>=0 && ny>=0 && nx<m && ny<n && !vis[nx][ny] && grid[nx][ny]==1){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }

        int ans=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1 && !vis[i][j]) ans++;

        return ans;
    }
};
