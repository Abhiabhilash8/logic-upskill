class Solution {
public:

    int f(int n){
        int x=0;
        while(n){
            x = (x*10 + n%10);
            n/=10;
        }

        return x;
    }
    int mirrorDistance(int n) {
        return abs(((f(n) - n)));
    }
};