// Last updated: 4/5/2026, 11:46:14 AM
class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char>rev(s.size(),'a');
        for(int i=0;i<s.size();i++){
            rev[s.size()-1-i]=s[i];

        }
        swap(s,rev);
        
    }
};