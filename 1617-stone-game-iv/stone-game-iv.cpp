class Solution {
public:
/*
    dp[i][t] = false -> dp[i + any sq][!t] == true
    dp[i][t] = true ->  dp[i + any sq][!t] == false

    dp[0][0] = 1 

    f(i , turn){

    }

    turn == 1 alice turn
    else bob turn
*/

    vector<int>sq;
    vector<vector<int>>dp;
    int k;
    bool f(int i , int turn){
        if(i > k) return turn;
        if(dp[i][turn] != -1) return dp[i][turn];
        bool a = false, b = true;
        for(auto s: sq){
            if(i + s > k) break;
            if(turn) a |= f(i + s , !turn);
            else b &= f(i + s , !turn);
        }

        if(turn) return dp[i][turn] = a;
        else return dp[i][turn] = b;

    }

    bool winnerSquareGame(int n) {
        k = n;
        for(int i = 1; i*i <= n; i++) sq.push_back(i*i);
        
        dp.assign(n+1 , vector<int>(2 , -1));

        return f(0 , 1);
    }
};