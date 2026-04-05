// Last updated: 4/5/2026, 11:47:41 AM
class Solution {
public:



    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
        for(int i=0;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){

                if(i==0&&j==0) dp[0][0]=triangle[0][0];
                else if(j>=triangle[i-1].size()) dp[i][j]=dp[i-1][j-1]+triangle[i][j];
                else if(j==0) dp[i][j]=dp[i-1][j]+triangle[i][j];
                else{
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
                }
            }
        }

            int minpath=INT_MAX,l=triangle.size()-1;
            for(int i=0;i<dp[l].size();i++){
                if(dp[l][i]<minpath) minpath=dp[l][i];
            }


            return minpath;
        
    }
};