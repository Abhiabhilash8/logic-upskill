class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>pmin(nums.size());
        pmin[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = nums.size() - 2; i >= 0; i--) pmin[i] = min(pmin[i + 1] , nums[i]);
        
        int cmax = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            cmax = max(cmax , nums[i]);
            if(cmax - pmin[i] <= k) return i;
        }

        return -1;
    }
};