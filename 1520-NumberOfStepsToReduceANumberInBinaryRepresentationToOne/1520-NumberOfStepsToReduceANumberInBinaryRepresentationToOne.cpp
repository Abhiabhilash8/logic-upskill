// Last updated: 4/5/2026, 11:44:23 AM
class Solution {
public:
    int numSteps(string s) {
        int c=0,ans=0;
        for(int i=s.size()-1;i>0;i--){
            if(c){
                if(s[i]=='1'){
                    s[i]='0';
                    c=1;
                }else{
                    s[i]='1';
                    c=0;}
            }


            if(s[i]=='1') {ans+=2;c=1;}
            else ans++;
            // cout<<s<<" "<<c<<" "<<ans<<endl;
        }
        if(c) ans++;

        return ans;
    }
};