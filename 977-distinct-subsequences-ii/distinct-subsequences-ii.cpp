class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int>lc(26 , 0);
        int cc = 1 , M = 1000000007;

        for(int i = 0; i < s.size(); i++){
            int k = cc;
            cc = ((2 * cc)%M - lc[s[i] - 'a'] + M) % M;
            
            lc[s[i] - 'a'] = k;
        }

        return (cc - 1 + M) % M ;
    }
};