class Solution {
public:
    // checks if 
    bool check(vector<bool>& vis , string &unq , char u , int& lp , vector<vector<bool>>&st , string &s){
        for(int i = lp+1; i<st.size(); i++){
            if(s[i] == u){
                int f = 0;
                for(int j = 0; j < unq.size(); j++){
                    if(!vis[j] && !st[i][unq[j] - 'a']){
                        f = 1;
                        break;
                    }
                }
                if(f==0){
                    lp = i;
                    return 1;
                }
            }
        }

        return false;
    }

    string smallestSubsequence(string s) {
        int n = s.size();
        vector<vector<bool>>st;
        vector<bool>f(26 , 0);
        set<char>te;
        for(int i = n-1; i>=0; i--){
            f[s[i] - 'a'] = 1;
            st.push_back(f);
            te.insert(s[i]);
        }
        string unq(te.begin() , te.end());
        vector<bool>vis(unq.size() , 0);
        reverse(st.begin() , st.end());
        string ans = "";
        int lp = -1;
        while(ans.size() != unq.size()){
            char cur;
            for(int i = 0; i<unq.size(); i++){
                if(!vis[i] && check(vis , unq , unq[i] , lp , st , s)){
                    // checks if unq[i] character is valid pick after last pick 
                    // i th unq letter is picked 
                    ans += unq[i];
                    vis[i] = 1;
                    break;
                }
            }
        }

        return ans;

    }
};