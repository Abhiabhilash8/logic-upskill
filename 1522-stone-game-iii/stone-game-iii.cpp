class Solution {
public:
    string stoneGameIII(vector<int>& sv) {
        int n = sv.size();
        vector<vector<int>>dp(n + 1 , vector<int>(2 , 0));
        vector<int>rs(n + 1 , 0);
        rs[n] = 0;
        for(int i = n-1; i>=0; i--) rs[i] = rs[i+1] + sv[i];
        for(int i = n-1; i>=0; i--){
            for(int turn = 0; turn < 2; turn++){
                dp[i][turn] = sv[i] + rs[i+1] - dp[i + 1][!turn];
                if(i + 1 < n) dp[i][turn] = max(dp[i][turn] , sv[i] + sv[i+1] + rs[i+2] - dp[i+2][!turn]);
                if(i + 2 < n) dp[i][turn] = max(dp[i][turn] , sv[i] + sv[i+1] + sv[i+2] + rs[i+3] - dp[i+3][!turn]);
            }
        }

        int ts = accumulate(sv.begin() , sv.end() , 0);
        if(2 * dp[0][1] > ts) return "Alice";
        else if(2 * dp[0][1] < ts) return "Bob";
        else return "Tie";
    }
};