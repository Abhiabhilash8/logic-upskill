// Last updated: 4/5/2026, 11:48:50 AM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int si=0,ei=nums.size()-1,mi;
        while(si<=ei){
            mi=(si+ei)/2;
            if(target>nums[mi]) si=mi+1;
            else ei=mi-1;            
        }
        if(si<nums.size()&&nums[si]==target) ans.push_back(si);
        si=0,ei=nums.size()-1;
        while(si<=ei){
            mi=(si+ei)/2;
            if(target>=nums[mi]) si=mi+1;
            else ei=mi-1;
        }
        if(ei>=0&&nums[ei]==target) ans.push_back(ei);
        if(nums.size()==0) {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        
        if(ans.size()==0){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};