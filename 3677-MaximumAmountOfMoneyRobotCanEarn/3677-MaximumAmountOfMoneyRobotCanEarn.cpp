// Last updated: 4/5/2026, 11:42:51 AM
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size(),m=coins[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,-1e9)));

        
            dp[0][0][2]=coins[0][0];
            if(coins[0][0]<0) dp[0][0][1]=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i+j==0) continue;

                if(i-1>=0){
                    dp[i][j][2]=dp[i-1][j][2]+coins[i][j];
                    dp[i][j][1]=dp[i-1][j][1]+coins[i][j];
                    dp[i][j][0]=dp[i-1][j][0]+coins[i][j];
                    if(coins[i][j]<0){
                        dp[i][j][1]=max(dp[i][j][1],dp[i-1][j][2]);
                        dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][1]);
                    }
                }
                if(j-1>=0){
                    dp[i][j][2]=max(dp[i][j][2],dp[i][j-1][2]+coins[i][j]);
                    dp[i][j][1]=max(dp[i][j][1],dp[i][j-1][1]+coins[i][j]);
                    dp[i][j][0]=max(dp[i][j][0],dp[i][j-1][0]+coins[i][j]);
                    if(coins[i][j]<0){
                        dp[i][j][1]=max(dp[i][j][1],dp[i][j-1][2]);
                        dp[i][j][0]=max(dp[i][j][0],dp[i][j-1][1]);
                    }
                }
            }
        }

        return max({dp[n-1][m-1][0] , dp[n-1][m-1][1] , dp[n-1][m-1][2]});
        
    }
};