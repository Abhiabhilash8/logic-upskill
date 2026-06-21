class Solution {
public:
    int maxIceCream(vector<int>& costs, int c) {
        vector<int>f(100001 , 0);
        for(auto um: costs) f[um]++;
        int ans = 0;
        for(int i = 1; i<f.size() && (c >= i); i++){
            int picks = min(c/i , f[i]);
            ans += picks;
            c -= picks * i;
        }

        return ans;
    }
};