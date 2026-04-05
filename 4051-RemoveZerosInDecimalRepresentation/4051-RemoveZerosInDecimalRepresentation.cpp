// Last updated: 4/5/2026, 11:42:01 AM
class Solution {
public:
    long long removeZeros(long long n) {
        long long ans=0;
        while(n){
            if(n%10) ans=ans*10+n%10;
            n=n/10;
        }
        long long temp=0;
        while(ans){
            temp=temp*10+ans%10;
            ans/=10;
        }

        return temp;
    }
};