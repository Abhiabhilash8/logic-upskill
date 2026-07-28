class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int>f(26 , 0);
        for(auto c: s) f[c - 'a']++;
        char c = '1';
        string ans(n , ' ');
        int p1 = 0 , p2 = n-1;

        for(int i = 0; i<26; i++){
            if(f[i] & 1){
                c = i + 'a';
                f[i]--;
            }

            while(f[i]){
                ans[p1++] = i + 'a';
                ans[p2--] = i + 'a';
                f[i] -= 2;
            }
        }

        if(n & 1) ans[p1] = c;

        return ans;

    }
};