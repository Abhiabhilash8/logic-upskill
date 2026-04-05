// Last updated: 4/5/2026, 11:43:14 AM
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int>fo(26,0),fe(26,0);
        for(int i=0;i<s1.size();i++){
            if(i&1){
                fo[s1[i]-'a']++;
                fo[s2[i]-'a']--;
            }else{
                fe[s1[i]-'a']++;
                fe[s2[i]-'a']--;
            }
        }

        for(int i=0;i<26;i++){
            if(fo[i] || fe[i]) return false;
        }
        return true;
    }
};