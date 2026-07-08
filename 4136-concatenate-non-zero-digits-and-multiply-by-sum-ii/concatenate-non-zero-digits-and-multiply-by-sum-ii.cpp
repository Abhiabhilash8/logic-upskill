class Solution {
public:
    typedef long long ll;
    ll M = 1000000007;
    ll MAX = 100001;
    vector<ll>pow;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        pow.resize(MAX);
        pow[0] = 1;
        for(int i =1; i<MAX; i++){
            pow[i] = (pow[i-1] * 10LL)%M;
        }

        vector<ll>ps(n + 1 , 0) , prenum(n + 1 , 0) , len(n + 1 , 0);
        for(int i = 0; i<n; i++){
            int d = s[i] - '0';
            if(d){
                ps[i + 1] = ps[i] + d;
                prenum[i+1] = (prenum[i] * 10LL + d)%M;
                len[i + 1] = len[i] + 1; 
            }else{
                ps[i+1] = ps[i];
                prenum[i+1] = prenum[i];
                len[i+1] = len[i];
            }
        }

        vector<int>ans;
        for(auto &q: queries){
            int l = q[0] , r = q[1] + 1;

            ll pnz = prenum[l] *1LL * pow[len[r] - len[l]] % M;
            int x = (int)(prenum[r] - pnz + M)%M;
            ans.push_back((x * (ps[r] - ps[l])) % M);
        }

        return ans;
    }
};