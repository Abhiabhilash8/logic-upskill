class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int sf = 0 , ef = 0;
        vector<int>f(52 , 0);
        if(k == n) return *max_element(nums.begin() , nums.end());
        for(int i = 0; i<n; i++){
            f[nums[i]]++;
            if(nums[i] == nums[0]) sf++;
            if(nums[i] == nums[n - 1]) ef++;
        }
        if(k == 1){
            int mv = -1;
            for(int i = 0; i < n; i++){
                if(f[nums[i]] == 1) mv = max(mv , nums[i]);
            }
            return mv;
        }
        if(nums[0] == nums[n-1]) return -1;

        if(sf > 1 && ef > 1) return -1;
        if(sf == 1 && ef == 1) return max(nums[0] , nums[n-1]);
        if(sf == 1) return nums[0];
        return nums[n-1];
    }
};