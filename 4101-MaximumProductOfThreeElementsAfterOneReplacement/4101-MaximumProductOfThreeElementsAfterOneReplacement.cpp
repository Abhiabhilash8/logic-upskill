// Last updated: 4/5/2026, 11:41:40 AM
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());

        long long ans=nums[nums.size()-1];
        ans*=nums[nums.size()-2];
        ans*=1e5;
        return ans;
    }
};