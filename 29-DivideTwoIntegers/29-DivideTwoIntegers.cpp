// Last updated: 4/5/2026, 11:48:54 AM
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==1) return dividend;
        if(dividend==divisor) return 1;


        bool sign=true;
        if((dividend>0&&divisor<0)||(dividend<0&&divisor>0)) sign = false;
        long n=llabs(dividend);
        long d=llabs(divisor);

        // int n=dividend;
        int ans=0,count;
        long int tans=0;
        while(n>=d){
            count=0;
            while(n>=d*(1ll<<(count+1))) count++;

            tans+=(1ll<<count);
            n=n-d*(1ll<<count);
        }

        if(tans>=(1ll<<31)){
            if(sign) return INT_MAX;
            else return INT_MIN;
        }
        // ans=tans;

        if(!sign) tans*=-1;

        return tans;
    }
};