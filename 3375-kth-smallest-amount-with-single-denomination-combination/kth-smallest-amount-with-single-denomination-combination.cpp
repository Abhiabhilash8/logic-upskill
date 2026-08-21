class Solution {
public:
    vector<long long>odd , even;

    void init(vector<int>&coins){
        int n = coins.size();

        for(int mask = 1; mask < (1 << n); mask++){
            long long lc = 1;

            for(int i = 0; i < n; i++)
                if((1 << i) & mask) lc = lcm(lc , coins[i]);

            if(__builtin_popcount(mask) & 1) odd.push_back(lc);
            else even.push_back(lc);
        }
    }

    long long count(long long x){
        long long c = 0;

        for(int i = 0; i < odd.size(); i++) c += x / odd[i];
        for(int i = 0; i < even.size(); i++) c -= x / even[i];


        return c;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        init(coins);
        long long l = 1 , h = 25ll * k + 1;

        while(h - l >= 1){
            long long m = l + (h - l) / 2;
            if(count(m) < k) l = m + 1;
            else h = m;
        }

        return h;
    }
};