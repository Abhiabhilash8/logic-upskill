// Last updated: 4/5/2026, 11:41:21 AM
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        vector<int>minv(nums.size(),nums.size());
        int minval=nums[nums.size()-1];
        for(int i=nums.size()-1;i>=1;i--){
            minval=min(minval,nums[i]);
            minv[i-1]=minval;
        }
        minv[nums.size()-1]=0;

        long long maxans=nums[0]-minv[0];
        long long  s=0;
        for(int i=0;i<nums.size()-1;i++){
            s+=nums[i];
            maxans=max(maxans,s-minv[i]);
        }

        return maxans;
    }
};