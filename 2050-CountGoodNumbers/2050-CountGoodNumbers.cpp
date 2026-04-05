// Last updated: 4/5/2026, 11:43:39 AM
class Solution {
public:
const long long MOD = 1e9 + 7;

    long long f(int n,long long exp){
        if(exp==0) return 1;

        long long temp=f(n,exp/2);
        if(exp&1) return (temp*n*temp)%MOD;
        else return (temp*temp)%MOD;
    }

    int countGoodNumbers(long long n) {
        
        long long ans=f(5,ceil(n*1.0/2))%MOD;
        long long ans1=f(4,n/2)%MOD;

        return (ans*ans1)%MOD;
    }
};