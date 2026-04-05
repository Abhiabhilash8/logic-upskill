// Last updated: 4/5/2026, 11:46:02 AM
class Solution {
public:
    int help(int maxs,vector<int>&nums){
        int ktemp=1,sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=maxs){
                sum+=nums[i];
            }
            else{
                ktemp++;
                sum=nums[i];
            }
        }
            return ktemp;
    }
    int splitArray(vector<int>& nums, int k) {
        // largest sum ranges to sum of array elements
        int low=*max_element(nums.begin(), nums.end()),high=0,mid;
        for(int i=0;i<nums.size();i++) high+=nums[i];

        while(low<=high){
            mid=(low+high)/2;
            if(help(mid,nums)<=k) high=mid-1;
            else low=mid+1;
        }
        return low;

    }
};