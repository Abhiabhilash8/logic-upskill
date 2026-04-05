// Last updated: 4/5/2026, 11:41:14 AM
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<bool>>>dp(n,vector<vector<bool>>(m,vector<bool>(1024+2,0)));
        dp[0][0][grid[0][0]]=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue;
                for(int xr=0;xr<1024;xr++){
                    bool k=0;
                    if(i>0 && (dp[i-1][j][xr^grid[i][j]])) k=1;
                    if(j>0 && (dp[i][j-1][xr^grid[i][j]])) k=1;

                    dp[i][j][xr]=k;
                }
            }
        }

        for(int xr=0;xr<1024;xr++){
            if(dp[n-1][m-1][xr]) return xr;
        }

        return 0;
        
    }
};