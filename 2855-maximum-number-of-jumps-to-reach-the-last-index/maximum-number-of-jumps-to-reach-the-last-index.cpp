class Solution {
public:
    int dp[1001];
    int maximumJumps(vector<int>& nums, int tg) {
        int n = nums.size();
        memset(dp, -1 ,sizeof(dp));
        dp[0] = 0;
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i ; j++){
                if(-tg <= nums[j] - nums[i] && nums[j] - nums[i] <= tg){
                    dp[i] = max(dp[i] , dp[j]);
                }
            }

            if(dp[i] != -1) dp[i]++;
        }

        return dp[n-1];

    }
};