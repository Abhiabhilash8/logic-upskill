// Last updated: 4/5/2026, 11:47:00 AM
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mpp;
        map<char,bool>mpp2;
        for(int i=0;i<s.size();i++){
            if(mpp[s[i]]==t[i]||(mpp[s[i]]=='\0'&&mpp2[t[i]]==false)){
                mpp[s[i]]=t[i];
                mpp2[t[i]]=true;;
                continue;
            }
            else return false;
        }
        return true;
    }
};