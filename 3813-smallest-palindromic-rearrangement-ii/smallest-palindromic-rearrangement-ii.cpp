class Solution {
public:

    long long nCr(int n , int r , int k){
        r = min(r , n - r);
        long long res = 1;
        for(int i = 1; i<=r; i++){
            res = res * (n - r + i) / i;
            if(res >= k) return k;
        }

        return res;
    }

    string smallestPalindrome(string s, int k) {
        char mid;
        int n = s.size();
        if(n&1) mid = s[n/2];
        vector<int>count(26 , 0);
        for(int i = 0; i<n; i++){
            if(n&1 && i == n/2) continue;
            count[s[i] - 'a']++;
        }
        for(int i = 0; i<26; i++) count[i] /= 2;

        string hr = "";
        int half = n/2;

        for(int i = 0; i<half; i++){
            bool isp = 0;
            for(int j = 0; j < 26; j++){
                if(count[j]){
                    count[j]--;
                    long long ways = 1;
                    int letters = 0;
                    for(int c = 0; c < 26; c++) letters += count[c];

                    for(int c = 0; c < 26; c++){
                        if(count[c]){
                            ways *= nCr(letters , count[c] , k);
                            letters -= count[c];
                        }
                        if(ways >= k) break;
                    }
                    if(ways >= k){
                        hr += (j + 'a');
                        isp = 1;
                        break;
                    }
                    k -= ways;
                    count[j]++;
                }
            }
            if(!isp) return "";
        }
        string rev = hr;
        reverse(rev.begin() , rev.end());
        if(n&1) hr += mid;
        return hr + rev;
    }
};