// Last updated: 4/5/2026, 11:41:18 AM
class Solution {
public:
    string reversePrefix(string s, int k) {
        string a = s.substr(0, k);
        reverse(a.begin(), a.end());
        return a + s.substr(k);
    }
};
