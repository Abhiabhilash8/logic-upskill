class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[i]) continue;

            if(i+1>s1.size() || s1[i+2]!=s2[i]) return false;
            swap(s1[i],s1[i+2]);
        }

        return true;
    }
};