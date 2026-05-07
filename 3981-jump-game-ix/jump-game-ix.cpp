class Solution {
public:
    static vector<int> maxValue(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> prefix(n);
        vector<int> ans(n);

        prefix[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], nums[i]);
        }

        int mini = INT_MAX;

        for(int i = n - 1; i >= 0; i--) {

            if(prefix[i] <= mini) {
                ans[i] = prefix[i];
            }
            else {
                ans[i] = ans[i + 1];
            }

            mini = min(mini, nums[i]);
        }

        return ans;
    }
};