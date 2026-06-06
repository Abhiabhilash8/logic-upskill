class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int rs = accumulate(nums.begin() , nums.end() , 0);
        int ls = 0;
        vector<int>a;
        for(int i = 0; i < nums.size(); i++){
            rs -= nums[i];
            a.push_back(abs(ls - rs));
            ls += nums[i];
        }

        return a;
    }
};