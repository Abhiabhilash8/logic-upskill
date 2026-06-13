class Solution {
public:
    vector<vector<long long>> dp;
    vector<long long> pref;
    const long long NEG = LLONG_MIN;

    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();

        dp.assign(m + 1, vector<long long>(n + 1, NEG));
        pref.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        for(int i = 0; i<=n; i++) dp[0][i] = 0;
        // f(k , i) = max(f(k , i+1) , f(k - 1 , i + valid len))
        // k 1 -> m   i = n -> 0

        long long ans = LLONG_MIN;

        for(int k = 1; k<=m ; k++){
            dp[k][n] = 0;
            priority_queue<pair<long long , int>>pq;
            for(int i = n-1; i>=0; i--){
                if(i + l <= n) {
                    pq.push({pref[i + l] + dp[k-1][i + l] , i + l});
                }

                dp[k][i] = dp[k][i+1];
                while(pq.size() && pq.top().second > i + r) pq.pop();
                if(pq.size()){
                    dp[k][i] = max(dp[k][i] , pq.top().first - pref[i]);
                }


            }

            ans = max(ans , dp[k][0]);
        }


        if(ans == 0){
            long long b = LLONG_MIN;
            for(int i = 0; i < n; i++){
                for(int j = i+l; j<= i+r && j<=n ; j++){
                    b = max(b , pref[j] - pref[i]);
                }
            }


            return b;
        }


        return ans;
    }
};