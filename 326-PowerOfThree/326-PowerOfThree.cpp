// Last updated: 4/5/2026, 11:46:17 AM
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        while(n){
            if(n==1) return true;
            if(n%3!=0) return false;
            else n=n/3;
        }

        return true;
    }
};