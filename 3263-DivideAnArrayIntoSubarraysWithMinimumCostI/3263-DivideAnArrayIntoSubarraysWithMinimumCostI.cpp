// Last updated: 4/5/2026, 11:43:06 AM
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans=nums[0];
        nums[0]=INT_MAX;
        sort(nums.begin(),nums.end());
        return ans+nums[0]+nums[1];
    }
};