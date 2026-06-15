class Solution {
public:
    vector<vector<bool>> ad = vector<vector<bool>>(10, vector<bool>(10));
    vector<vector<bool>> po = vector<vector<bool>>(10, vector<bool>(10));

    vector<vector<vector<bool>>> buddi =
        vector<vector<vector<bool>>>(10, vector<vector<bool>>(10, vector<bool>(10)));

    bool sud(vector<vector<char>>& board, int i, int j) {
        if (i == 9)
            return true;

        int ni = (j == 8) ? i + 1 : i;
        int nj = (j == 8) ? 0 : j + 1;

        if (board[i][j] != '.')
            return sud(board, ni, nj);

        for (char c = '1'; c <= '9'; c++) {
            int x = c - '0';

            if (ad[i][x] || po[j][x] || buddi[i / 3][j / 3][x])
                continue;

            ad[i][x] = po[j][x] = buddi[i / 3][j / 3][x] = true;
            board[i][j] = c;

            if (sud(board, ni, nj))
                return true;

            ad[i][x] = po[j][x] = buddi[i / 3][j / 3][x] = false;
            board[i][j] = '.';
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int x = board[i][j] - '0';
                    ad[i][x] = true;
                    po[j][x] = true;
                    buddi[i / 3][j / 3][x] = true;
                }
            }
        }

        sud(board, 0, 0);
    }
};