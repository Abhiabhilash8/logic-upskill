class Solution {
public:
    using ll = long long;
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = ranges::max(nums);
        vector<int>freq(mx+1 , 0);
        vector<ll>gcd(mx + 1 , 0);
        for(auto &a: nums) freq[a]++;
        for(int i = mx; i>0; i--){
            ll sm = 0, extra = 0;
            for(int j = i; j<=mx; j+=i) sm += freq[j] , extra += gcd[j];
            
            gcd[i] = sm * (sm - 1) / 2 - extra;
        }

        partial_sum(gcd.begin() , gcd.end() , gcd.begin());
        vector<int>res(queries.size());
        for(int i = 0; i < queries.size(); i++) res[i] = ranges::upper_bound(gcd , queries[i]) - gcd.begin();

        return res;
    }
};