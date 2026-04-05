// Last updated: 4/5/2026, 11:49:02 AM
class Solution {
public:
    bool isValid(string s) {
        stack<char>prts;
        int c=0;
        for(int i=0;i<s.size();i++){
            if(c!=0&&((prts.top()=='{'&&s[i]=='}')||(prts.top()=='('&&s[i]==')')||(prts.top()=='['&&s[i]==']'))){
                prts.pop();
                c--;
            }
            else{
                prts.push(s[i]);
                c++;
            }
        }
     


       if(c==0)
       return true;
       else
       return false;
        
        
        
    }
};