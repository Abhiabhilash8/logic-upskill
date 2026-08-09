class Solution {
public:
    vector<vector<vector<int>>>dp;
    int f(int i , int m, int turn , vector<int>&p){
        if(i >= p.size()) return 0;
        if(dp[i][m][turn] != -1) return dp[i][m][turn];
        int mk = INT_MIN,mi = INT_MAX , s = 0;
        for(int j = i; j < p.size() && j - i < 2 * m; j++){
            s += p[j];
            int k = f(j + 1 , max(j - i + 1 , m) , !turn , p);
            mk = max(mk , s + k );
            mi = min(mi , k);
        }

        if(turn) return dp[i][m][turn] = mi;
        else return dp[i][m][turn] = mk;
    }
    int stoneGameII(vector<int>& p) {
        int n = p.size();
        dp.assign(n+1 , vector<vector<int>>(n + 1 , vector<int>(2 , -1)));
        int s = f(0 , 1 , 0 , p);
        return s;
    }
};