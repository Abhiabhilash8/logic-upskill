class Solution {
public:

    vector<vector<int>>dp;

    int f(int i , int s , vector<int>&p){
        if(p.size() <= i) return 0;
        if(dp[s][i] != INT_MIN) return dp[s][i];

        int r;
        if(s&1) r = max(f(i + 1 , s , p) ,  p[i] + f(i + 2 , !s , p));
        else r = max(f(i + 1 , s , p) , -p[i] + f(i + 1 , !s , p));

        return dp[s][i] = r;
    }

    int maxProfit(vector<int>& p) {
        dp.resize(2 , vector<int>(p.size() , INT_MIN));
        return f(0 , 0 , p);
    }
};