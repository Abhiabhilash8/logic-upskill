// Last updated: 4/5/2026, 11:45:30 AM
class Solution {
public:

    bool f(string &s,int ind,int count,vector<vector<int>>&dp){
        if(ind==s.size()||count<0) return count==0;
        if(dp[ind][count]!=-1) return dp[ind][count];
        else if(s[ind]=='(') return dp[ind][count] = f(s,ind+1,count+1,dp);
        else if(s[ind]==')') return dp[ind][count] = f(s,ind+1,count-1,dp);

            return dp[ind][count] = f(s,ind+1,count+1,dp)||f(s,ind+1,count-1,dp)||f(s,ind+1,count,dp);
        
    }

    bool checkValidString(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size()+1,-1));

        return f(s,0,0,dp);
    }
};