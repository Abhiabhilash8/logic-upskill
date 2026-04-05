// Last updated: 4/5/2026, 11:45:46 AM
class Solution {
public:
    int longestPalindromeSubseq(string s2) {
        int n=s2.size();
        string s1=s2;reverse(s2.begin(),s2.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=n-1;i>=0;i--)
            for(int j=n-1;j>=0;j--){
                if(s1[i]==s2[j]) dp[i][j]=1+dp[i+1][j+1];
                else dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
            }

        return dp[0][0];

    }
};