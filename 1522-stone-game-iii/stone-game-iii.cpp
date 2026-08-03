class Solution {
public:
    string stoneGameIII(vector<int>& sv) {
        int n = sv.size();
        vector<int>dp(n + 1 , 0);
        vector<int>rs(n + 1 , 0);
        rs[n] = 0;
        for(int i = n-1; i>=0; i--) rs[i] = rs[i+1] + sv[i];
        for(int i = n-1; i>=0; i--){
                dp[i] = sv[i] + rs[i+1] - dp[i + 1];
                if(i + 1 < n) dp[i] = max(dp[i] , sv[i] + sv[i+1] + rs[i+2] - dp[i+2]);
                if(i + 2 < n) dp[i] = max(dp[i] , sv[i] + sv[i+1] + sv[i+2] + rs[i+3] - dp[i+3]);
        }

        int ts = accumulate(sv.begin() , sv.end() , 0);
        if(2 * dp[0] > ts) return "Alice";
        else if(2 * dp[0] < ts) return "Bob";
        else return "Tie";
    }
};