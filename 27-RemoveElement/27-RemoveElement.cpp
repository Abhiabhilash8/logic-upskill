// Last updated: 4/5/2026, 11:48:57 AM
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i=0;i<nums.size();i++){
            if(val==nums[i]){
            nums.erase(nums.begin()+i);
            i--;
            }
        }
        return nums.size();
    }
};