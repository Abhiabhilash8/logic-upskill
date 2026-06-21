class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1) , cnt(n , 1);
        for(int i=1;i<n;i++){
            int c = 0;
            for(int j = 0; j<i; j++){
                if(nums[j] < nums[i]){
                    if(dp[i] < 1 + dp[j]){
                        c = 0;
                        dp[i] = 1 + dp[j];
                    }
                    if(dp[i] == 1 + dp[j]){
                        c += cnt[j];
                    }
                }
            }

            cnt[i] = max(1 , c);
        }

        int c = 0;
        int tg = *max_element(dp.begin() , dp.end());
        for(int i = 0; i<n; i++){
            if(dp[i] == tg) c += cnt[i];
        }

        return c;
    }
};