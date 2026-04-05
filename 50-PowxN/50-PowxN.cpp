// Last updated: 4/5/2026, 11:48:39 AM
class Solution {
public:
    double find(double x,long long int n){
        if(n==0) return 1;
        else if(n&1) return x*find(x,n-1);
            double temp=find(x,n/2);
            return temp*temp;
    }

    double myPow(double x, int n) {
        if(x==1) return 1;
    long long N=n;
    double ans=1;
 
        if(N<0) N=-N;

        ans = find(x,N);
        if(n<0) ans=1.0/ans;
        return ans;
  }
};