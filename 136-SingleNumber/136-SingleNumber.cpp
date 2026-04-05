// Last updated: 4/5/2026, 11:47:30 AM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int val:nums){
            ans^=val;
        }
        return ans;
    }
};