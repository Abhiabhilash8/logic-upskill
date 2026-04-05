// Last updated: 4/5/2026, 11:42:58 AM
class Solution {
public:
    bool doesAliceWin(string s) {
        int c=0;
        for(int i=0;i<s.size();i++){
            if((s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u')){
                c=1;
                break;
            }
        }

        if(c==0) return false;
        else return true;
    }
};