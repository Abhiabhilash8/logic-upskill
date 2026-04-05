// Last updated: 4/5/2026, 11:44:56 AM
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int topleft=INT_MAX,topright=INT_MAX,top=INT_MAX;

                if(j>0) topleft=dp[i-1][j-1];
                if(j<n-1) topright=dp[i-1][j+1];
                top=dp[i-1][j];

                dp[i][j]=min(top,min(topleft,topright))+matrix[i][j];
            }
        }

        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }


        return ans;
    }
};