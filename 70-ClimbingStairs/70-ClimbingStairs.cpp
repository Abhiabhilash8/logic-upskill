// Last updated: 4/5/2026, 11:48:18 AM
class Solution {
public:

    int climbStairs(int n) {
        if(n<=1) return n;
        int a=0,b=1,c;
        for(int i=2;;i++){
            c=a+b;
            a=b;
            b=c;
            if(i==n+1) return c;
        }
        
    }
};