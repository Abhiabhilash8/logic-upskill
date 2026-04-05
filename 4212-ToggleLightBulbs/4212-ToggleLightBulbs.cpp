// Last updated: 4/5/2026, 11:41:13 AM
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,int>mpp;
        for(auto ele: bulbs){
            mpp[ele]++;
        }
        vector<int>ans;
        for(auto &it: mpp){
            if(it.second&1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};