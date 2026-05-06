class Solution {
public:
    static vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size();
        int cols = box[0].size();

        vector<vector<char>> ans(cols, vector<char>(rows, '.'));

        for (int i = 0; i < rows; i++) {
            int empty = cols - 1;

            for (int j = cols - 1; j >= 0; j--) {

                if (box[i][j] == '*') {
                    ans[j][rows - 1 - i] = '*';
                    empty = j - 1;
                }

                else if (box[i][j] == '#') {
                    ans[empty][rows - 1 - i] = '#';
                    empty--;
                }
            }
        }

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();