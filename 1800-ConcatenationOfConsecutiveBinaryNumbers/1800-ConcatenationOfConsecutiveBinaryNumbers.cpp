// Last updated: 4/5/2026, 11:44:02 AM
class Solution {
public:
    long long M=1000000007;

    int concatenatedBinary(int n) {
        long long ans=0;
        for(int i=1;i<=n;i++){
            int l=log2(i)+1;
            ans=((ans<<l)%M + i%M)%M;
        }

        return ans;
    }
};