class Solution {
public:

    vector<vector<int>>dp;

    int f(int i , int s , vector<int>&p){
        if(p.size() == i) return 0;
        if(dp[i][s] != INT_MIN) return dp[i][s];
        int r;
        if(s == 0) r = max(f(i + 1 , 0 , p) , -p[i] + f(i + 1 , 1 , p));
        else if( s == 1 ) r = max(f(i + 1 , 1 , p) ,  p[i] + f(i + 1 , 2 , p));
        else if( s == 2 ) r = max(f(i + 1 , 2 , p) ,- p[i] + f(i + 1 , 3 , p));
        else r = max(f(i + 1 , 3 , p) , p[i]);

        return dp[i][s] = r;
    }

    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size() , vector<int>(4 , INT_MIN));
        return f(0 , 0 , prices);
    }
};