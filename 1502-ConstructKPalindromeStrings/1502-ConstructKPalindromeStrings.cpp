// Last updated: 4/5/2026, 11:44:26 AM
class Solution {
public:
    bool canConstruct(string s, int k) {
        // if((s.size()-k<0)) return false;
        if((s.size()<k)) return false;
        int arr[26]={0};
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
        }
        int odd=0;
        for(int i=0;i<26;i++){
            if(arr[i]%2==1) odd++;
        }
        if(odd<=k) return true;
        else return false;
    }
};