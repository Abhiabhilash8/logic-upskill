class Solution {
public:

    pair<int,int> dp[10][2];

    pair<int,int> ddp(int idx , bool tight , string &sn){
        if(idx == sn.size()) return {0,1};
        if(dp[idx][tight].first != -1) return dp[idx][tight];

        int ub = tight? sn[idx] - '0' : 9;
        int curans = 0 , ended = 0;
        for(int i = 0; i<=ub ; i++){
            pair<int , int> c = ddp(idx + 1 , tight && ub == i , sn);
            curans += c.first;
            if(i == 1) curans += c.second;
            ended += c.second;
        }

        return dp[idx][tight] = {curans , ended};

    }

    int countDigitOne(int n) {
        string sn = to_string(n);
        memset(dp , -1 , sizeof(dp));
        return ddp(0 , true , sn).first;
    }
};