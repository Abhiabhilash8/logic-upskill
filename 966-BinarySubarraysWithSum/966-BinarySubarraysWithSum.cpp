// Last updated: 4/5/2026, 11:44:57 AM
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int csum=0,ans=0;
        map<int,int>presum;
        presum[0]=1;
        for(int i=0;i<nums.size();i++){
            csum+=nums[i];
            ans+=presum[csum-goal];
            presum[csum]++;
        }

        return ans;
    }
};