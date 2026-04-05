// Last updated: 4/5/2026, 11:46:38 AM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0||((n&(n-1))!=0)) return false;
        else return true;
    }
};