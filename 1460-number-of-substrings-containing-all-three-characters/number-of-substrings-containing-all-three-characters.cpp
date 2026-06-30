class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = -1, b = -1, c = -1;
        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            a = s[i] == 'a'? i:a;
            b = s[i] == 'b'? i:b;
            c = s[i] == 'c'? i:c;

            ans += 1 + min({a , b , c});
        }

        return ans;
    }
};