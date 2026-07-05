class Solution {
public:
/*
    dp[i][j] = max sum possible to reach from i,j to 0,0 , num of ways possible
    dp[i][j].fist = b[i][j] + max(b[i-1][j].first , b[i][j-1].first , b[i-1][j-1].first) , 
    dp[i][j].second = freq of max in 3 options
    dp[0][0] = {0 , 1}
*/
    vector<int> pathsWithMaxScore(vector<string>& b) {
        int MOD = 1000000007;
        int n = b.size() , m = b[0].size();
        vector<vector<pair<long long , long long>>>dp(n , vector<pair<long long , long long>>(m));
        dp[0][0] = {0 , 1};

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){

                if(b[i][j] == 'X'){
                    dp[i][j] = {0 , 0};
                    continue;
                }
                if(i == 0){
                    if(j && dp[i][j-1].second) dp[i][j] = {dp[i][j-1].first + b[i][j] - '0' , dp[i][j - 1].second};
                    continue;
                }
                else if(j == 0){
                    if(dp[i-1][j].second)dp[i][j] = {dp[i-1][j].first + b[i][j] - '0' , dp[i - 1][j].second};
                    continue;
                }else{
                    long long mk = max({dp[i-1][j].first , dp[i][j-1].first , dp[i-1][j-1].first});
                    long long ways = 0;
                    if (mk == dp[i-1][j].first) ways = (ways + dp[i-1][j].second) % MOD;
                    if (mk == dp[i][j-1].first) ways = (ways + dp[i][j-1].second) % MOD;
                    if (mk == dp[i-1][j-1].first) ways = (ways + dp[i-1][j-1].second) % MOD;
                    if(!ways) continue;
                    dp[i][j] = {(i == n-1 && j == m-1)? mk : b[i][j]-'0' + mk , ways};
                }

            }
        }
        
        vector<int>ans;
        ans.insert(ans.begin() , {(int)dp[n-1][m-1].first , (int)dp[n-1][m-1].second});
        return ans;
    }
};