class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long cs = 0,ans = 0 , vp = 0;
        map<long long , long long>mpp;
        mpp[0] = 1;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == target) vp += mpp[cs++];
            else vp -= mpp[--cs];

            mpp[cs]++;
            ans += vp;
        }

        return ans;
    }
};