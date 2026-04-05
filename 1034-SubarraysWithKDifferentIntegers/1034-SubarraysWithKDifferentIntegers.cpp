// Last updated: 4/5/2026, 11:44:49 AM
class Solution {
public:
    int f(vector<int>&nums,int k){

        int n=nums.size(),a=0,l=0;
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            while(mpp.size()>k) {
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            a+=i-l+1;
        }

        return a;
    }



    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};