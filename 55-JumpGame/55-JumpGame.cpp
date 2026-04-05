// Last updated: 4/5/2026, 11:48:33 AM
class Solution {
public:

    bool f(int ind,vector<int>&dp,vector<int>&nums){
        if(ind==nums.size()-1) return true;
        if(ind>=nums.size()) return false;
        if(dp[ind]!=-1) return dp[ind];

        bool x=false;
        for(int i=1;i<=nums[ind];i++){
            x|=f(ind+i,dp,nums);
            if(x) return dp[ind]= true;
        }

        return dp[ind]=false;
    }

    bool canJump(vector<int>& nums) {

        vector<int>dp(nums.size()+1,-1);

        return f(0,dp,nums);
        
    }
};