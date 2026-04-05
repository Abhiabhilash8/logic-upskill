// Last updated: 4/5/2026, 11:41:43 AM
class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(nums.size(),vector<int>(2e4,-1));
        dp[0][0]=0,dp[0][nums[0]]=1;
        // for(int i=0;i<n;i++) dp[0][nums[i]]=1;
        for(int i=1;i<n;i++){
            for(int k=0;k<2e4;k++){
                if((k ^ nums[i]) <2e4 && dp[i-1][k ^ nums[i]] != -1) dp[i][k]=max(dp[i-1][k ^ nums[i]]+1,dp[i][k]);
                if(dp[i-1][k] != -1) dp[i][k]=max(dp[i-1][k] , dp[i][k]);
            }
        }

        if(dp[n-1][target] == -1) return -1;
        else return n-dp[n-1][target];
        
    }
};