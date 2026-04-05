// Last updated: 4/5/2026, 11:41:23 AM
class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int a1=0,a2=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<k;i++){
            a1+=nums[i];
            a2+=nums[nums.size()-i-1];
        }

        return a2-a1;
    }
};