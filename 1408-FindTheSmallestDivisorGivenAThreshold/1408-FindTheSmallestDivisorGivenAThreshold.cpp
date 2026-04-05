// Last updated: 4/5/2026, 11:44:32 AM
class Solution {
public:
    int help(int mid,vector<int>&nums){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=ceil((float(nums[i]))/(float(mid)));
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end()),mid;
        while(low<=high){
            mid=(low+high)/2;
            if(help(mid,nums)<=threshold) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};