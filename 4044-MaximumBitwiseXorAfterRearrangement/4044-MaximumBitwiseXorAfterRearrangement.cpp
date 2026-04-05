// Last updated: 4/5/2026, 11:42:05 AM
class Solution {
public:
    string maximumXor(string s, string t) {
        int sim=0,o=0;
        for(int i=0;i<s.size();i++){
            if(t[i]=='1'){ sim++;t[i]='0';}
        }

        for(int i=0;i<s.size() && sim;i++){
            if(s[i]=='0'){ t[i]='1',sim--;}
        }


        o=sim;
        for(int i=s.size()-1;i>=0 && o;i--){
            if(t[i]!='1'){t[i]='1';
            o--;}
        }

        cout<<t<<endl;

        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]) s[i]='1';
            else s[i]='0';
        }

        

        
        return s;
    }
};