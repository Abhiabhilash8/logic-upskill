// Last updated: 4/5/2026, 11:41:46 AM
class Solution {
public:
    bool p(int n){
        int i=2;
        for(;i<n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    
    int largestPrime(int n) {
    if(n==1) return 0;
        int ans=2,mans=2;
        for(int i=3;i<=n && ans<=n;i++){
            if(!p(i)) continue;
            ans+=i;
            if(ans>n) break;
             if(p(ans) && ans<=n) mans=max(mans,ans);
        }
        return mans;
        
    }
};