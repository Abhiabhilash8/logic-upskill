// Last updated: 4/5/2026, 11:45:11 AM
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        int ptr1=0,ptr2=0;
        for(int i=0;i<s.size();i++){
             ptr1=i;
             ptr2=0;
             while(ptr2<goal.size()){
                if(s[ptr1]==goal[ptr2]){
                    ptr1=(ptr1+1)%s.size(),ptr2++;
                    continue;
                }
                else{
                   break;
                }
                if(ptr1==i) break;
             }
             if(ptr2==goal.size()) return true;
        }
        return false;
    }
};