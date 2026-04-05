// Last updated: 4/5/2026, 11:44:52 AM
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        for(int i=nums.size()-1;i>=2;i--){
            if(nums[i]<nums[i-1]+nums[i-2]) return nums[i]+nums[i-1]+nums[i-2];
        }

        return 0;
    }
};