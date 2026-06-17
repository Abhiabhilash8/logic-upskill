class Solution {
public:
    int minDistance(string w1, string w2) {
        int n1 = w1.size() , n2 = w2.size();
        if(n1 < n2) return minDistance(w2 , w1);

        vector<vector<int>>dp(n1 + 1 , vector<int>(n2 + 1 , 0));
        for(int i = 0; i<=n2; i++) dp[n1][i] = n2 - i;
        for(int i = 0; i<=n1; i++) dp[i][n2] = n1 - i;


        for(int i = n1 - 1; i>=0; i--)
            for(int j = n2 - 1; j>=0; j--)
                dp[i][j] = (w1[i] == w2[j])? dp[i+1][j+1] : 1 + min({dp[i+1][j] , dp[i][j+1] , dp[i+1][j+1]});
        

        return dp[0][0];

    }
};