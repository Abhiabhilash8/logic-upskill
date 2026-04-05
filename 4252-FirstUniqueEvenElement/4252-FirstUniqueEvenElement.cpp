// Last updated: 4/5/2026, 11:40:51 AM
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++) mpp[nums[i]]++;

        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0 && mpp[nums[i]]==1) return nums[i];
        }
        return -1;
    }
};