class Solution {
public:
    int minFlips(string s) {
        int z=0,o=0,n=s.size();
        if(n<=2) return 0;

        for(auto c: s){
            if(c == '1') o++;
            else z++;
        }

        return max(0,min(z , o - 1 - (s[0] == s[n-1] && s[0] == '1')));
    }
};