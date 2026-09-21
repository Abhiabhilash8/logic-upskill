class Solution {
public:
    #define ll long long
    vector<long long> resultArray(vector<int>& nums, int k) {
        ll n = nums.size();
        vector<ll>dp(k , 0), ans(k , 0);
        for(int i = 0; i < n; i++){
            vector<ll>ndp(k , 0);
            ll c = nums[i] % k;
            ndp[c]++ , ans[c]++;
            for(int j = 0; j < k; j++){
                ndp[(c * j) % k] += dp[j];
                ans[(c * j) % k] += dp[j];
            }
            dp = ndp;
        }

        return ans;
    }
};