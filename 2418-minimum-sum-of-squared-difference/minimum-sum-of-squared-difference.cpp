class Solution {
public:
typedef long long ll;
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        priority_queue<pair<ll , ll>>pq;
        ll k = k1 + k2;
        vector<ll>f(1e5 + 1 , 0);
        for(int i = 0; i < nums1.size(); i++) f[abs(nums1[i] - nums2[i])]++;
        for(int i = 0; i <= 1e5 ; i++) if(f[i]) pq.push({i , f[i]});
        pq.push({0 , 0});
        while(k && pq.top().first != 0){
            auto [val , cfreq] = pq.top();
            pq.pop();
            auto [sval , sfreq] = pq.top();
            pq.pop();

            ll dif = val - sval;
            ll krem = min(k , dif * cfreq);

            k -= krem;
            ll nvalue = val - krem / cfreq;
            ll nfreq = cfreq;
            if(krem % cfreq){
                pq.push({nvalue , cfreq - (krem % cfreq)});
                if(nvalue - 1 == sval){
                    pq.push({nvalue - 1 , (krem % cfreq) + sfreq});
                }else{
                    pq.push({nvalue - 1 , (krem % cfreq)});
                    pq.push({sval , sfreq});
                }
            }else{
                if(nvalue == sval) pq.push({nvalue , cfreq + sfreq});
                else{
                    pq.push({nvalue , cfreq});
                    pq.push({sval , sfreq});
                }
            } 
        }

        ll ans = 0;
        while(pq.size()){
            auto [x , freq] = pq.top();
            pq.pop();
            ans += freq * (x * x);
        }

        return ans;
    }
};