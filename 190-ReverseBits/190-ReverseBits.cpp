// Last updated: 4/5/2026, 11:47:12 AM
class Solution {
public:
    int reverseBits(int n) {
        int x=1;
        int ans=0,c=0;
        while(c<31){
            c++;
            ans|=(x&n);
            ans<<=1;
            n>>=1;
        }
        return ans;
    }
};