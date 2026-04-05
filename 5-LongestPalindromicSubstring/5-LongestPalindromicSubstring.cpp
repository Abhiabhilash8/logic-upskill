// Last updated: 4/5/2026, 11:49:18 AM
class Solution {
public:
string c(int i,int j,string &s){
    int c=0;
    c-=(i==j);
    while(i>=0 && j<s.size() && s[i]==s[j]) {c+=2;i--,j++;}
    return s.substr(i+1,c);
}
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            string a=c(i,i,s),b;
            if(i<s.size()-1 && s[i]==s[i+1]){
                b=c(i,i+1,s);
                if(ans.size()<b.size()) ans=b;
            }
            if(a.size()>ans.size()) ans=a;
        }

        return ans;
    } 
};