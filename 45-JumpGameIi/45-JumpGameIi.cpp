// Last updated: 4/5/2026, 11:48:42 AM
class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp){

        if(i>=nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];

            int x=1e8;
            for(int j=1;j<=nums[i];j++){
                if(i+j<nums.size())
                x=min(x,1+f(i+j,nums,dp));
            }

        return dp[i]=x;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);      

        return f(0,nums,dp);
    }
};