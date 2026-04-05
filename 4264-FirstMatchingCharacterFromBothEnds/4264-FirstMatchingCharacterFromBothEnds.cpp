// Last updated: 4/5/2026, 11:40:44 AM
class Solution {
public:
    int firstMatchingIndex(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]==s[s.size()-i-1]) return i;
        }
        return -1;
    }
};