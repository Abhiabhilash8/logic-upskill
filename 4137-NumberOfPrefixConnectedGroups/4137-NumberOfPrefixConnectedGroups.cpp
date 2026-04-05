// Last updated: 4/5/2026, 11:41:34 AM
class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        map<string,int>mpp;
        for(auto w: words){

            if(w.size()<k) continue;
            mpp[w.substr(0,k)]++;
        }
        int ans=0;
        for(auto &it: mpp){
            if(it.second>=2) ans++;
        }

        return ans;
    }
};