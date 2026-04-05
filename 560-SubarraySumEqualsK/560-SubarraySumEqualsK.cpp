// Last updated: 4/5/2026, 11:45:38 AM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i=0,ans=0;
        int prefixsum=0;
        map<int,int>mpp;
        mpp[0]=1;
        for(i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            int req=prefixsum-k;
            ans+=mpp[req];
            mpp[prefixsum]++;
        }
        return ans;
    }
};