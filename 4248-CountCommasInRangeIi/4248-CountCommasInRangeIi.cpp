// Last updated: 4/5/2026, 11:40:54 AM
class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        if(n>=1000) ans+=min((long long)n-1000+1,(long long)1e6-1000);
        if(n>=1e6) ans+=2*min((long long)n-1e6+1,(long long)1e9-1e6);
        if(n>=1e9) ans+=3*min((long long)n-1e9+1,(long long)1e12-1e9);
        if(n>=1e12) ans+=4*min((long long)n-1e12+1,(long long)1e15-1e12);
        if(n>=1e15) ans+=5;

        return ans;
        
    }
};