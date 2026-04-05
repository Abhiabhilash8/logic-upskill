// Last updated: 4/5/2026, 11:44:09 AM
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        const long long MOD = 1e9 + 7;

        vector<vector<long long>> maxDP(rows, vector<long long>(cols));
        vector<vector<long long>> minDP(rows, vector<long long>(cols));

        maxDP[0][0] = minDP[0][0] = grid[0][0];

        for (int i = 1; i < rows; i++) {
            long long val = grid[i][0];
            maxDP[i][0] = minDP[i][0] = maxDP[i - 1][0] * val;
        }

        for (int j = 1; j < cols; j++) {
            long long val = grid[0][j];
            maxDP[0][j] = minDP[0][j] = maxDP[0][j - 1] * val;
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                long long val = grid[i][j];

                long long fromTopMax = maxDP[i - 1][j] * val;
                long long fromTopMin = minDP[i - 1][j] * val;
                long long fromLeftMax = maxDP[i][j - 1] * val;
                long long fromLeftMin = minDP[i][j - 1] * val;

                maxDP[i][j] = max({fromTopMax, fromTopMin, fromLeftMax, fromLeftMin});
                minDP[i][j] = min({fromTopMax, fromTopMin, fromLeftMax, fromLeftMin});
            }
        }

        long long result = maxDP[rows - 1][cols - 1];

        if (result < 0) return -1;

        return result % MOD;
    }
};