// Last updated: 4/5/2026, 11:48:19 AM
class Solution {
public:
    int mySqrt(int n) {
        int i=1,c=0;
        while(n>0){
         n=n-i;
         if(n>=0)
         c++;
         i=i+2;
        }
        // if(n==0)
        // c--;
        return c;
    }
};