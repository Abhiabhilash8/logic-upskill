class Solution {
public:

    bool c(int m , vector<int>&nums , int k){
        int cs = 0 , kcount = 1;
        for(int i = 0; i < nums.size(); i++){
            if(cs + nums[i] <= m){
                cs += nums[i];
            }else{
                kcount++;
                cs = nums[i];
            }
        }

        return kcount <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin() , nums.end()) - 1 , h = 1e9;
        while(h - l > 1){
            int m = l + (h - l) / 2;
            if(c(m , nums , k)) h = m;
            else l = m;
        }

        return h;
    }
};