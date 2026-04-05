// Last updated: 4/5/2026, 11:45:26 AM
class Solution {
public:
    int countBinarySubstrings(string s) {
        char f=s[0];
        int cur=0,prev=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==f) cur++;
            else {
                prev=cur;
                cur=1;
                f=s[i];
            }
            if(cur<=prev) ans++;
        }
        return ans;


    }
};