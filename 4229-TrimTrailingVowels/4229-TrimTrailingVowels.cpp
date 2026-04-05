// Last updated: 4/5/2026, 11:41:02 AM
class Solution {
public:
    string trimTrailingVowels(string s) {
        set<char>st={'a','e','i','o','u'};
        string a="";
        int f=0;
        for(int i=s.size()-1;i>=0;i--){
            if(f==0 && st.find(s[i])!=st.end()){
                continue;
            }else f=1;

            a+=s[i];
        }
        reverse(a.begin(),a.end());
        return a;
        
        
    }
};