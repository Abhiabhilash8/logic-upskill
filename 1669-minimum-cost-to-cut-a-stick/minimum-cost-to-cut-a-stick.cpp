class Solution {
public:

    vector<vector<int>>dp;
    int f(int i , int j , vector<int>&cuts){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int a = INT_MAX;

        for(int k = i;  k<=j; k++)
            a = min(a , cuts[j + 1] - cuts[i-1] + f(i , k - 1 , cuts) + f(k + 1 , j , cuts));

        return dp[i][j] = a;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin() , cuts.end());
        int m = cuts.size();
        dp.resize(m , vector<int>(m , -1));
        return f(1 , m - 2 , cuts);
    }
};