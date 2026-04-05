// Last updated: 4/5/2026, 11:47:11 AM
class Solution {
public:
    int hammingWeight(int n) {
        int c=0;
        while(n>0){
            if(n%2==1)
            c++;
            n/=2;

        }
        return c;
    }
};