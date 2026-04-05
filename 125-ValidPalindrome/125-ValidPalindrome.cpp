// Last updated: 4/5/2026, 11:47:36 AM
class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0,j=s.size()-1;i<=j;){
            if(s[i]>='A'&&s[i]<='Z') 
            s[i]+=32;
            if(s[j]>='A'&&s[j]<='Z') 
            s[j]+=32;
            if(!((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))){
                i++;
            continue;
            }
            if(!((s[j]>='a'&&s[j]<='z')||(s[j]>='0'&&s[j]<='9'))){
                j--;
            continue;
            }
            if(s[i]!=s[j])
            return false;
            i++;
            j--;

        }
        return true;
    }
};