// Last updated: 4/5/2026, 11:41:17 AM
class Solution {
public:
    string largestEven(string s) {
        int ptr1=s.size()-1;
        while(ptr1>=0 && ((s[ptr1]-'0')&1)) ptr1--;
        if(ptr1<0) return "";
        else return s.substr(0,ptr1+1);
    }
};