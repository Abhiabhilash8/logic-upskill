class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ml = 0;
        bool f = false;
        map<int , int>mpp;
        int p = 0;
        for(int i = 0; i<nums.size(); i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]] > k) f = 1;
            while(f){
                mpp[nums[p]]--;
                if(nums[p] == nums[i]){
                    f = 0;
                    p++;
                    break;
                }
                p++;
            }


            ml = max(ml , i - p + 1);
        }


        return ml;
    }
};