class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int l=n-1;l>0;l--){
            for(int r=l+1;r<=n;r++){
                if(s[l-1]==s[r-1]) l + 1 <= r - 1? dp[l][r]=dp[l+1][r-1]:0;
                else dp[l][r]=1+min(dp[l+1][r],dp[l][r-1]);
            }
        }

        return dp[1][n];
    }
};