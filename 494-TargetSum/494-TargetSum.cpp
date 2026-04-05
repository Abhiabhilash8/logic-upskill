// Last updated: 4/5/2026, 11:45:51 AM
class Solution {
public:
int solve(vector<int>& nums,int target,int ind){
    int n=nums.size();
    if(ind==n) return target==0;

    int s=0;
    s+=solve(nums,target-nums[ind],ind+1)+solve(nums,target+nums[ind],ind+1);
    return s;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        return  (solve(nums,target,0));
    }
};