class Solution {
public:

    bool check(int m , vector<int>&nums , int k){
        int cursum = 0, parts = 1;
        for(int i = 0; i < nums.size(); i++){
            if(cursum + nums[i] <= m){
                cursum += nums[i];
            }else{
                parts++;
                cursum = nums[i];
            }
        }


        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin() , nums.end()) - 1 , high = 1000000005;

        while(high - low > 1){
            int m = low + (high - low) / 2;

            if(check(m , nums , k)) high = m;
            else low = m;
        }

        return high;
    }
};