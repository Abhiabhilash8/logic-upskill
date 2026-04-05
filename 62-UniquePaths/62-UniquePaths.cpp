// Last updated: 4/5/2026, 11:48:27 AM
class Solution {
public:

    int f(int i,int j,int m,int n,vector<vector<int>>&dp){
        if((i>m)||(j>n)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m&&j==n) return 1;

        return dp[i][j]=f(i+1,j,m,n,dp)+f(i,j+1,m,n,dp);

    }

    int uniquePaths(int m, int n) {

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        return f(0,0,m-1,n-1,dp);
        
    }
};