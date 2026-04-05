// Last updated: 4/5/2026, 11:46:29 AM
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            mpp[t[i]]--;
        }
        for(int i=0;i<s.size();i++){
            if(mpp[s[i]]!=0) return false;
        }
        return true;
    }
};