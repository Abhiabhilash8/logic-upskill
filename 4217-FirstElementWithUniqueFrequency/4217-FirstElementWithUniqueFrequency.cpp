// Last updated: 4/5/2026, 11:41:07 AM
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int,int>f,ff;
        for(int i=0;i<nums.size();i++) f[nums[i]]++;
        for(auto &it: f) ff[it.second]++;

        for(int i=0;i<nums.size();i++){
            if(ff[f[nums[i]]]==1) return nums[i];
        }
        return -1;
    }
};