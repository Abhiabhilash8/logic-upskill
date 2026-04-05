// Last updated: 4/5/2026, 11:49:15 AM
class Solution {
public:
    int myAtoi(string s) {
        int ans=0;;
        int f=0,i=0,n=s.size();
        bool neg=false;
        while(i<n&&(s[i]==' ')) i++;
        if(s[i]=='-') {
            i++;
            neg=true;
        }
        else if(s[i]=='+') i++;

        while(i<n&&s[i]=='0') i++;

        int pdigits=INT_MAX%10;
        int ndigits=INT_MIN%10*-1;

        for(i;i<n;i++){
            if(!(s[i]>='0'&&s[i]<='9')) break;
            int num=s[i]-'0';

            if(!neg){
                if(ans>INT_MAX/10||(ans==INT_MAX/10&&num>=pdigits)) return INT_MAX;
            }else{
                if(ans>-1*(INT_MIN/10)||(ans==-1*(INT_MIN/10)&&num>=ndigits)) return INT_MIN;
            }
            ans=ans*10+num;
        }



        if(neg) ans*=-1;
        return ans;

        
    }
};