// Last updated: 4/5/2026, 11:46:46 AM
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size()&&j<i+2+k;j++){
                if(nums[i]==nums[j]&&(j-i)<=k)
                return true;
            }
        }
        return false;
        
    }
};