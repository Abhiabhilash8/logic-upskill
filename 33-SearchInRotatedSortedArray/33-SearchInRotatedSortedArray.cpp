// Last updated: 4/5/2026, 11:48:51 AM
class Solution {
public:
    int search(vector<int>& nums, int target) {

        int si=0,ei=nums.size()-1,mi;
        while(si<=ei){
           mi=(si+ei)/2;
           if(nums[mi]==target) return mi;
          if(nums[si]<=nums[mi]){
            if(target<nums[mi]&&target>=nums[si]) ei=mi-1;
            else si=mi+1;
          }
          else{
            if(target>nums[mi]&&target<=nums[ei]) si=mi+1;
            else ei=mi-1;
          }
        
    }
    return -1;
    }
};