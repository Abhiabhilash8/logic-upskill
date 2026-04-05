// Last updated: 4/5/2026, 11:48:49 AM
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int si=0,ei=nums.size()-1,mi=0;
        while(si<=ei){
            mi=(si+ei)/2;
            if(nums[mi]==target)    return mi;
            else if(target>nums[mi])    si=mi+1;
            else    ei=mi-1;
        }
         return ei+1;
    }
};