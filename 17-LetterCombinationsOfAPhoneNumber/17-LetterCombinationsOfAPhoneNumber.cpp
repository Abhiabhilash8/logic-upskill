// Last updated: 4/5/2026, 11:49:06 AM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void f(int i, vector<string>& ans, string &s, string &digits,
           vector<string> &map) {
        
        if (i == digits.size()) {
            ans.push_back(s);
            return;
        }

        int num = digits[i] - '0';
        for (char c : map[num]) {
            s.push_back(c);
            f(i + 1, ans, s, digits, map);
            s.pop_back();  // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;

        vector<string> map = {
            "",     "",     "abc",  "def",
            "ghi",  "jkl",  "mno",  "pqrs",
            "tuv",  "wxyz"
        };

        string s = "";
        f(0, ans, s, digits, map);
        return ans;
    }
};
