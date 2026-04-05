// Last updated: 4/5/2026, 11:42:25 AM
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i=0,n=nums.size(),prev=0;
        while(i+1<nums.size() && nums[i]<nums[i+1]) i++;
        if(prev==i) return false;
        prev=i;
        while(i+1<nums.size() && nums[i+1]<nums[i]) i++;
        if(prev==i) return false;
        prev=i;
        while(i+1<nums.size() && nums[i+1]>nums[i]) i++;
        return prev!=i && i==n-1;
    }
};