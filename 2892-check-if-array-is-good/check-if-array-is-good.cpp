class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int c = 1;
        for(auto e: nums){
            mpp[e]++;
            mpp[c++]--;
        }
        mpp[nums.size()-1]--;
        mpp[nums.size()]++;

        for(auto &it: mpp){
            if(it.second) return false;
        }
        return true;
    }
};