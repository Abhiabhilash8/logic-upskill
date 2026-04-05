// Last updated: 4/5/2026, 11:44:06 AM
class Solution {
public:
    int maxDepth(string s) {
        int balance=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') balance++;
            if(s[i]==')') balance--;
            ans=max(ans,balance);
        }
        return ans;
    }
};