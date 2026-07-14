class Solution {
public:
    int M = 1e9 + 7;
    int n;
    int dp[201][201][201];
    int s(int i , int g1 , int g2 , vector<int>&nums){
        if(i == n) return (g1 != 0 && g1 == g2);

        int &ans = dp[i][g1][g2];
        if(ans != -1) return ans;
        ans = 0;
        ans = s(i + 1 , g1 , g2 , nums);

        int ng1 = (g1 == 0) ? nums[i] : gcd(g1, nums[i]);
        int ng2 = (g2 == 0) ? nums[i] : gcd(g2, nums[i]);

        ans = (ans + s(i + 1 , ng1 , g2 , nums))%M;
        ans = (ans + s(i + 1 , g1 , ng2 , nums))%M;

        return ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp , -1 , sizeof(dp));
        return s(0 , 0 , 0 ,nums);
    }
};