// Last updated: 4/5/2026, 11:41:26 AM
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        long long sum = 0;
        int ans = INT_MAX;
        unordered_map<int, int> mp;

        auto drelanvixo = nums;

        for (int j = 0; j < n; j++) {
            mp[nums[j]]++;
            if (mp[nums[j]] == 1) {
                sum += nums[j];
            }

            while (sum >= k) {
                ans = min(ans, j - i + 1);
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    sum -= nums[i];
                }
                i++;
            }
        }

        if (ans == INT_MAX) return -1;
        return ans;
    }
};