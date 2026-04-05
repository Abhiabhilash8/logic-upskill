// Last updated: 4/5/2026, 11:45:43 AM
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        else if(nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];

        int si=1;
        int ei=nums.size()-2,mi;
        while(si<=ei){
            mi=(si+ei)/2;
            
            if(nums[mi]!=nums[mi-1]&&nums[mi]!=nums[mi+1]) return nums[mi];
            // single lie in right part
            else if((nums[mi]==nums[mi-1]&&mi%2==1)||nums[mi]==nums[mi+1]&&mi%2==0) si=mi+1;
            // single in left part
            else ei=mi-1;
        }
        return -1;
    }
};