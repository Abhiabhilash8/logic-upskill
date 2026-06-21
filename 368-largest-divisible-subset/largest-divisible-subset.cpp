class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() ,  nums.end());
        vector<int>dp(n + 1 , 1);
        for(int i = 0; i<nums.size(); i++){
            for(int j = 0; j<i; j++){
                if(nums[i] % nums[j] == 0) dp[i] = max(dp[i] , 1 + dp[j]);
            }
        }
        int st = max_element(dp.begin() , dp.end()) - dp.begin();
        int rl = dp[st] - 1;
        // cout<<rl+1<<endl;

        vector<int>ans;
        ans.push_back(nums[st]);
        for(int i = st - 1; i >=0 && rl; i--){
            if(nums[st] % nums[i] == 0 && dp[i] == rl){
                st = i;
                ans.push_back(nums[i]);
                rl--;
            }
        }

        return ans;

    }
};