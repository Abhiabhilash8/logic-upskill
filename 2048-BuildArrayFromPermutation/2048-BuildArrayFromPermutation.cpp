// Last updated: 4/5/2026, 11:43:41 AM
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++) ans[i]=nums[nums[i]];
        return ans;
    }
};