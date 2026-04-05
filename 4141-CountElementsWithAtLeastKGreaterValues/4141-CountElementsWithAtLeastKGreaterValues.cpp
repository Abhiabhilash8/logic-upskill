// Last updated: 4/5/2026, 11:41:32 AM
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if(k==0) return nums.size();
        sort(nums.begin(),nums.end());
        int i=nums.size()-k-1;
        while(i>=0 && nums[i]==nums[i+1]) i--;

        return i+1;
    
    }
};