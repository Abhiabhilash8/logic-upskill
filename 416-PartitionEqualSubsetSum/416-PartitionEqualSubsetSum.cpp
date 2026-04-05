// Last updated: 4/5/2026, 11:46:00 AM
class Solution {
public:

    bool f(int ind,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(ind<0) return false;
        if(ind==0) return nums[0]==target;
        if(dp[ind][target]!=-1) return dp[ind][target];

        bool pick = false,nonpick = false;

        nonpick=f(ind-1,target,nums,dp);

        if(target>nums[ind])
        pick = f(ind-1,target-nums[ind],nums,dp);

        return dp[ind][target]=pick||nonpick;

    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(sum%2==1) return false;
        // vector<int>dp(sum/2+1,-1);
        vector<vector<int>>dp(nums.size(),vector<int>(sum/2+1,-1));
        int target=sum/2;
        return f(nums.size()-1,target,nums,dp);
        
    }
};