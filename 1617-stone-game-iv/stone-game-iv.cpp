class Solution {
public:

/*
    dp[i] = winning state of cur player when i stones are remaining 
    for any s if dp[i-s] == false, --> prev player loose, hence cur player wins 
*/

    bool winnerSquareGame(int n) {
        vector<int>sq;
        for(int i = 1; i*i <= n; i++) sq.push_back(i*i);
        vector<bool>dp(n +1 , false);

        dp[0] = false;          //cur player loose when 0 stones are left
        for(int i = 1; i<=n; i++){
            for(auto s: sq){
                if(i - s < 0) break;
                if(!dp[i - s]){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};