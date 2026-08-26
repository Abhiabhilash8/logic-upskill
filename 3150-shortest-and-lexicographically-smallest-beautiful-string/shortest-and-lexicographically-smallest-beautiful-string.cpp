class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = s;
        int c = 0 , p = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '1') c++;
            if(c < k) continue;

            while(c >= k){
                if(s[p++] == '1') c--;
            }

            string d = s.substr(p - 1 , i - p + 2);
            if((ans.size() == d.size() && ans > d) || ans.size() > d.size()) ans = d;
        }

        if(p == 0) return "";
        else return ans;
    }
};