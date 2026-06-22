class Solution {
public:
    vector<int>dp;
    int f(int i , string &s , vector<vector<bool>>&pal){
        if(i == s.size() ) return -1;
        if(dp[i] != -1) return dp[i];

        int a = INT_MAX;
        for(int k = i; k<s.size() ; k++){
            if(pal[i][k]) a = min(a , 1 + f(k + 1 , s , pal));
        }

        return dp[i] = a;
        


    }

    int minCut(string s) {
        dp.resize(s.size() + 1 ,-1);
        vector<vector<bool>>pal(s.size() , vector<bool>(s.size() , false));
        
        for(int i = 0; i<s.size(); i++){
            pal[i][i] = 1;
            int ki = i, kj = i;
            while(ki >= 0 && kj<s.size() && s[ki] == s[kj]) pal[ki--][kj++] = 1;
            if(i > 0 && s[i] == s[i-1]){
                ki = i-1,kj=i;
                while(ki >= 0 && kj<s.size() && s[ki] == s[kj]) pal[ki--][kj++] = 1;
            }
        }

        return f(0 , s , pal);
    }
};