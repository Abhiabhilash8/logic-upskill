// Last updated: 4/5/2026, 11:47:05 AM
class Solution {
public:
    bool isHappy(int n) {
        if(n==1)    return 1;
        if(n<=6)    return 0;
       int sum=0;
    while(n!=0){
        sum+=(n%10)*(n%10);
        n/=10;
    }
        return isHappy(sum);
    }
};