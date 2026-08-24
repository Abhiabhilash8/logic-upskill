class Solution {
public:
    vector<long long>p , dp;

    long long f(int i , vector<int>&sn){
        if(i == sn.size() - 1) return p[sn.size() - 1];
        if(dp[i] != INT_MIN) return dp[i];

        long long noooo = f(i + 1 , sn);

        return dp[i] =  max(noooo , p[i] - noooo);
    }

    int stoneGameVIII(vector<int>& sn) {
        long long s = 0;
        dp.assign(sn.size() , INT_MIN);
        for(int i = 0; i<sn.size(); i++){
            s += sn[i];
            p.push_back(s);
        }

        return f(1 , sn);
    }
};