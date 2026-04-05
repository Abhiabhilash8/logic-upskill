// Last updated: 4/5/2026, 11:46:28 AM
class Solution {
public:
    int addDigits(int n) {
        int s=0;
        while(1){
            s+=n%10;
            n/=10;
            if(n==0&&s<10)
            return s;
            else if(n==0&&s>9){

            n=s;
            s=0;
            }

        }
    }
};