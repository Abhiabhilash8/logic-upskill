// Last updated: 4/5/2026, 11:48:25 AM
class Solution {
public:


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1]) return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));


        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){
                if(i==0&&j==0) dp[i][j]=1;
                else{
                int left=0,top=0;
                if(j>0&&!(obstacleGrid[i][j-1])) left = dp[i][j-1];
                if(i>0&&!(obstacleGrid[i-1][j])) top = dp[i-1][j];

                dp[i][j]=left+top;
                }
            }
        }

        return dp[m-1][n-1];
        
    }
};