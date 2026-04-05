// Last updated: 4/5/2026, 11:49:16 AM
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int b;
        int a;
        // if(x<0)a=-x;
        a = x;

        while (a != 0) {
            b = a % 10;
            if(rev>INT_MAX/10||rev== INT_MAX/10 &&b>7) return 0;
            if(rev<INT_MIN/10||rev== INT_MIN/10 &&b<-8) return 0;          
            rev = rev * 10 + b;
            a = a / 10;
        }
        // if(x<0)return -rev;
        return rev;
    }
};