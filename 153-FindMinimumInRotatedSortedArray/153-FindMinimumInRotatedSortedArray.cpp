// Last updated: 4/5/2026, 11:47:19 AM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int si=0,ei=n-1,mi;
        while(1){
            mi=(si+ei)/2;  
            if(nums[si]<=nums[mi]&&nums[mi]<=nums[ei]) return nums[si];
            else if(nums[si]>nums[ei]&&nums[mi]>nums[mi+1]) si=mi+1;
            else if(nums[si]>nums[ei]&&nums[mi]<nums[mi-1]) si=mi;
            else if(nums[si]>nums[ei]&&nums[mi]>nums[ei]) si=mi;
            else ei=mi;
        }
    }
};