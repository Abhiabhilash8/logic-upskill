class Solution {
public:

    vector<vector<vector<int>>>dp;

    bool f(int i , int j , vector<vector<char>>& g , int c){
        c += g[i][j] == '(' ? 1 : -1;
        if(c < 0) return 0;
        int n = g.size() , m = g[0].size();
        if(c == 0 && i == n -1 && j == m - 1) return 1;
        if(dp[i][j][c] != -1) return dp[i][j][c];

        bool t = 0;
        if(i + 1 < n) t |= f(i + 1 , j , g , c);
        if(j + 1 < m) t |= f(i , j + 1 , g , c);

        return dp[i][j][c] = t; 
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size();
        dp.assign(n , vector<vector<int>>(m , vector<int>(n + m , -1)));
        return f(0 , 0 , grid , 0);
    }
};