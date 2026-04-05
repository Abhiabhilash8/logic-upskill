// Last updated: 4/5/2026, 11:48:30 AM
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size(),c=0;
        for(int i=n-1;i>=0;i--){
            
            if(s[i]==' '&&c!=0)
            break;

            else if(s[i]!=' ') c++;
        }
        return c;
        
    }
};