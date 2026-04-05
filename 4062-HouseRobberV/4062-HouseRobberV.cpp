// Last updated: 4/5/2026, 11:41:56 AM
class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<long long>dp(nums.size()+1,0);
        dp[1]=nums[0];
        for(int i=2;i<=nums.size();i++){
            dp[i]=max(dp[i-1],nums[i-1]+dp[i-2]);
            if(colors[i-1]!=colors[i-2]) dp[i]=max(dp[i],nums[i-1]+dp[i-1]);

            // cout<<nums[i-1]+dp[i-2]<<" "<<dp[i]<<endl;
        }

        // for(int i=0;i<=nums.size();i++) cout<<dp[i]<<" ";

        return dp[nums.size()];
    }
};