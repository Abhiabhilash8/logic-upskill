// Last updated: 4/5/2026, 11:45:18 AM
class Solution {
public:
int isp(int x){
    if(x==1) return false;
    for(int i=2;i<x;i++) if(x%i==0) return false;
    return true;
}
    int countPrimeSetBits(int left, int right) {
        int a=0;
        for(int i=left;i<=right;i++) 
            if(isp(__builtin_popcount(i)))
                a++;
        return a;

    }
};