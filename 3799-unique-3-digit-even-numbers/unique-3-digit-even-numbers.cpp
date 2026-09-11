class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int>f(10 , 0);
        int ans = 0;
        for(int d: digits) f[d]++;
        for(int i = 100;  i<1000; i += 2){
            unordered_map<int,int>mpp;
            int k = i;
            while(k){
                mpp[k%10]++;
                k /= 10;
            }
            bool fl = 0;
            for(auto it: mpp){
                if(it.second > f[it.first]){
                    fl = 1;
                    break;
                }
            }
            if(!fl) ans++;
        }

        return ans;
    }
};