// Last updated: 4/5/2026, 11:41:06 AM
class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        string t=s;
        sort(t.begin(),t.end());
        if(t==s) return 0;
        if(s[0]==t[0] || s[n-1]==t[n-1]) return 1;
        int sl=0,sh=0;
        if(t[0]==t[1]) sl=1;
        if(t[n-1]==t[n-2]) sh=1;
        if(s[0]!=t[n-1] || s[n-1]!=t[0] || sl || sh) return 2;
        if(n<=2) return -1;
        return 3;
    }
};