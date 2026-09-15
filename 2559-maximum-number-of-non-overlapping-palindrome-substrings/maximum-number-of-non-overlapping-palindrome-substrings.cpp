class Solution {
public:

    int pal(string &s , int st , int i , int k){
        int l = i , r = i , n = s.size();
        while(l >= st && r < n && s[l] == s[r]){
            if(r - l + 1 >= k) return r;
            l--,r++;
        }

        l = i , r = i + 1;

        while(l >= st && r < n && s[l] == s[r]){
            if(r - l + 1 >= k) return r;
            l--,r++;
        }

        return -1;
    }

    int f(int st , string &s , int k){
        int ans = 0;
        for(int i = st ; i < s.size(); i++){
            int eind = pal(s , st , i , k);
            if(eind == -1) continue;
            return 1 + f(eind + 1 , s , k);
        }

        return 0;
    }

    int maxPalindromes(string s, int k) {
        return f(0 , s , k);
    }
};