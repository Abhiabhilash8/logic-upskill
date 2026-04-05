// Last updated: 4/5/2026, 11:42:45 AM
class Solution {
public:
    string generateString(string pattern, string target) {
        int n = pattern.size(), m = target.size();
        int len = n + m - 1;

        vector<char> res(len, '?');
        vector<bool> fixed(len, false);

        applyTrueConstraints(pattern, target, res, fixed, n, m);
        fillDefault(res);
        
        if (!applyFalseConstraints(pattern, target, res, fixed, n, m))
            return "";

        return string(res.begin(), res.end());
    }

private:
    void applyTrueConstraints(string &pattern, string &target,
                              vector<char> &res, vector<bool> &fixed,
                              int n, int m) {
        for (int i = 0; i < n; i++) {
            if (pattern[i] != 'T') continue;

            for (int j = 0; j < m; j++) {
                int idx = i + j;

                if (res[idx] == '?' || res[idx] == target[j]) {
                    res[idx] = target[j];
                    fixed[idx] = true;
                } else {
                    res.clear(); // mark invalid
                    return;
                }
            }
        }
    }

    void fillDefault(vector<char> &res) {
        for (char &c : res)
            if (c == '?') c = 'a';
    }

    bool applyFalseConstraints(string &pattern, string &target,
                               vector<char> &res, vector<bool> &fixed,
                               int n, int m) {
        if (res.empty()) return false;

        for (int i = 0; i < n; i++) {
            if (pattern[i] != 'F') continue;

            if (matches(res, target, i, m)) {
                if (!breakMatch(res, target, fixed, i, m))
                    return false;
            }
        }
        return true;
    }

    bool matches(vector<char> &res, string &target, int start, int m) {
        for (int j = 0; j < m; j++)
            if (res[start + j] != target[j])
                return false;
        return true;
    }

    bool breakMatch(vector<char> &res, string &target,
                    vector<bool> &fixed, int start, int m) {
        for (int j = m - 1; j >= 0; j--) {
            int idx = start + j;
            if (fixed[idx]) continue;

            for (char c = 'a'; c <= 'z'; c++) {
                if (c != target[j]) {
                    res[idx] = c;
                    return true;
                }
            }
        }
        return false;
    }
};