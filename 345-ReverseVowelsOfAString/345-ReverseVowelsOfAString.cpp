// Last updated: 4/5/2026, 11:46:13 AM
class Solution {
public:
    string reverseVowels(string s) {
        vector<char>v;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
               v.push_back(s[i]); 
            }
        }
            int j=0;
            for(int i=0;i<=s.size()-1;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
               s[i]=v[j++];
            }
        }
    return s;
    }
};