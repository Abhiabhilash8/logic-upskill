class Solution {
public:
    vector<vector<int>>dp;
    int p(vector<int>&nums , int i , int j , int turn){
        if(dp[i][j] != -1) return dp[i][j];
        if(i == j) {
            return turn * nums[i];
        }
        if(turn){
            int mk = 0;
            mk = max(mk ,nums[i] + p(nums , i + 1 , j , 0));
            mk = max(mk ,nums[j] + p(nums , i , j - 1 , 0));
            return dp[i][j] = mk;
        }else{
            int mk = INT_MAX;
            mk = min(mk , p(nums , i + 1 , j , 1));
            mk = min(mk , p(nums , i , j - 1 , 1));
            return dp[i][j] = mk;
        }

    }

    bool predictTheWinner(vector<int>& nums) {
        dp.assign(nums.size() , vector<int>(nums.size() , -1));
        return accumulate(nums.begin() , nums.end() , 0) <= 2* p(nums , 0 , nums.size() - 1 , 1);
    }
};