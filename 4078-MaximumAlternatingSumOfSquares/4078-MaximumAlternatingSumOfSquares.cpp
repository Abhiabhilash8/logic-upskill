// Last updated: 4/5/2026, 11:41:50 AM
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int n=ceil(nums.size()*1.0/2.0)-1;

        // int n=nums.size()/2;
        int i=0;
        long long ans=0;
        for(i=0;i<=n;i++){
            ans+=(nums[i]*nums[i]);
        }
        for(i;i<nums.size();i++){
            ans-=(nums[i]*nums[i]);
        }


        return ans;
    }
};