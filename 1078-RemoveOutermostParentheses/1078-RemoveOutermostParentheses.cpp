// Last updated: 4/5/2026, 11:44:40 AM
class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance=0;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(balance!=0) ans+='(';
                balance++;
            }
            else{
                balance--;
                if(balance!=0) ans+=')';
            }
        }
        return ans;
        
    }
};