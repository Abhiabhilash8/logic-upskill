// Last updated: 4/5/2026, 11:46:18 AM
class Solution {
public:


    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,1e9);

        dp[0]=0;
        for(int i=1;i<=amount;i++){
            dp[i]=1e9;

            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0) dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }

        int temp= dp[amount];
        return (temp>=1e9)? -1:temp;
    }
};