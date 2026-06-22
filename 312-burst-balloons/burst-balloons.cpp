class Solution {
public:
    vector<vector<int>>dp;
    int f(int i , int j , vector<int>&nums){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int a = INT_MIN;
        for(int k = i; k<=j; k++){
            a = max(a , nums[i-1] * nums[j+1] * nums[k] + f(i , k - 1 , nums) + f(k + 1 , j , nums ));
        }

        return dp[i][j] = a;
    }

    int maxCoins(vector<int>& nums) {
        dp.resize(nums.size() + 3 , vector<int>(nums.size() + 2 , -1));
        nums.insert(nums.begin() , 1);
        nums.push_back(1);
        return f(1 , nums.size() - 2 , nums);
    }
};