// Last updated: 4/5/2026, 11:46:09 AM
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int ans=1;
        int c=9;
        int k=1;
        for(int i=0;i<n-1;i++){

            ans+=((c--)*k);
            k*=(c+1);
        }

        return 9*ans+1;

    }
};