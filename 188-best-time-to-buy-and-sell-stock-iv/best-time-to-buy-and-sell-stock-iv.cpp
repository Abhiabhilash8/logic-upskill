class Solution {
public:

    vector<vector<int>>dp;
    int k;

    int f(int i , int s , vector<int>&p){
        if(p.size() == i || s == k) return 0;
        if(dp[i][s] != INT_MIN) return dp[i][s];
        int r;
        if(!(s&1)) r = max(f(i + 1 , s , p) , -p[i] + f(i + 1 , s + 1 , p));
        else if(s&1) r = max(f(i + 1 , s , p) ,  p[i] + f(i + 1 , s+1 , p));

        return dp[i][s] = r;
    }

    int maxProfit(int kg, vector<int>& prices) {
        k = 2 * kg;
        dp.resize(prices.size() , vector<int>(2*k , INT_MIN));
        return f(0 , 0 , prices);
    }
};