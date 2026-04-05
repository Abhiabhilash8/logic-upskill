// Last updated: 4/5/2026, 11:42:44 AM
class Solution {
public:
bool ndec(vector<int>&nums){
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]>nums[i+1]) return false;
    }
    return true;
}
    int minimumPairRemoval(vector<int>& nums) {
        if(ndec(nums)) return 0;
        int mini=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[mini]+nums[mini+1]>nums[i]+nums[i+1]) mini=i;
        }
        nums[mini]=nums[mini]+nums[mini+1];
        nums.erase(nums.begin()+mini+1);
        return 1+minimumPairRemoval(nums);


    }
};