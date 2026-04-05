// Last updated: 4/5/2026, 11:41:15 AM
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size(),m=nums2.size();
        long long INF=-1e18;
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(m+1,vector<long long>(k+2,INF)));
        for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) dp[i][j][0]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                for(int c=1;c<=k;c++){
                   long long sk=max({dp[i+1][j][c],dp[i][j+1][c]}),tk=INF;
                    if(dp[i+1][j+1][c-1]!=INF) tk=1LL*nums1[i]*nums2[j]+dp[i+1][j+1][c-1];
                dp[i][j][c]=max(tk,sk);
                }
            }
        }

        
        return dp[0][0][k];
    }
};