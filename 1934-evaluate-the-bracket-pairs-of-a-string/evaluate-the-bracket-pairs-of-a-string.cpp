class Solution {
public:
    string evaluate(string s, vector<vector<string>>& kn) {
        map<string , string>mpp;
        for(int i = 0; i < kn.size(); i++){
            mpp[kn[i][0]] = kn[i][1];
        }
        int i = 0 , j;
        string ans = "";
        while(i < s.size()){
            if(s[i] != '('){
                ans += s[i++];
                continue;
            }
            j = i;
            while(s[j] != ')') j++;
            string k = s.substr(i + 1 , j- i - 1);
            if(mpp.find(k) != mpp.end()) ans += mpp[k];
            else ans += '?';
            i = j + 1;
        }

        return ans;
    }
};