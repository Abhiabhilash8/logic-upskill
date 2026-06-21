class Solution {
public:

    bool  check(string &s1 , string &s2){
        if(s1.size() != s2.size()-1) return false;
        int i = 0,j=0;
        while(i<s1.size() && j<s2.size()){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }else j++;
        }

        return (j - i == 0) || (j - i == 1);
    }

    int longestStrChain(vector<string>& w) {
        sort(w.begin() , w.end() , [](string &a , string &b){
            return a.size() < b.size();
        });
        int n = w.size();

        vector<int>dp(n , 1);
        
        for(int i = 1; i<n; i++)
            for(int j = 0; j<i; j++)
                if(check(w[j] , w[i])) dp[i] = max(dp[i] , 1 + dp[j]);


        return *max_element(dp.begin() , dp.end());
    }
};