// Last updated: 4/5/2026, 11:48:21 AM
class Solution {
public:
    string addBinary(string a, string b) {
        int ptra=a.size()-1,ptrb=b.size()-1;

        int c=0;
        string ans="";
        while((ptra+1)&&(ptrb+1)){
            int s=c^(a[ptra]-'0')^(b[ptrb]-'0');
            c=(a[ptra]-'0')&(b[ptrb]-'0')|(c&((a[ptra]-'0')^(b[ptrb]-'0')));
            ans+=(s+'0');

            ptra--,ptrb--;
        }

        while(ptra+1){
            int s=c^(a[ptra]-'0');
            c=c&(a[ptra]-'0');
            ans+=(s+'0');
            ptra--;
        }
        while(ptrb+1){
            int s=c^(b[ptrb]-'0');
            c=c&(b[ptrb]-'0');
            ans+=(s+'0');

            ptrb--;
        }

        if(c) ans+=(c+'0');


        reverse(ans.begin(),ans.end());
        return ans;
    }
};