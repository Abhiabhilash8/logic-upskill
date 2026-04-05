// Last updated: 4/5/2026, 11:48:07 AM
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int si=0,ei=nums.size()-1,mi;
        while(si<=ei){
            mi=(si+ei)/2;
            if(nums[mi]==target) return true;
            if(nums[mi]==nums[si]&&nums[mi]==nums[ei]){
                si++;
                ei--;
            }
            // first half  sorted case
            else if(nums[mi]>=nums[si]){
                if(nums[si]<=target&&nums[mi]>=target)  ei=mi-1;
                else si=mi+1;
            }
            // right half  sorted case
            else{
                if(target>=nums[mi]&&target<=nums[ei]) si=mi+1;
                else ei=mi-1;
            }
        }
        return false;
    }
};