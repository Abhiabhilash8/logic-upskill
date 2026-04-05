// Last updated: 4/5/2026, 11:47:15 AM
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1||nums[0]>nums[1]) return 0;
        if(nums[nums.size()-1]>nums[nums.size()-2]) return nums.size()-1;        
        int si=1,ei=nums.size()-2,mi;

        while(si<=ei){
            mi=(si+ei)/2;
            if(nums[mi]>nums[mi-1]&&nums[mi]>nums[mi+1]) return mi;
            else if(nums[mi]>nums[mi-1]) si=mi+1;
            else ei=mi-1;
        }
        return 0;   
    }
};