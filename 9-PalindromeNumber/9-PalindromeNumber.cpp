// Last updated: 4/5/2026, 11:49:14 AM
class Solution {
public:
    bool isPalindrome(int x) {
        long int c=0;
        long int n=x;
        if(x>=0)
        for(int i=0;n!=0;i++){
            c=c*10+n%10;
            n/=10;
        }
        if(c==x)
        return 1;
        else
        return 0;
    }
};