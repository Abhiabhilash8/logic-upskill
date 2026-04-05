// Last updated: 4/5/2026, 11:45:04 AM
class Solution {
public:
    int binaryGap(int n) {
        int cur=0,mc=0,f=0;
        while(n){
            if(n%2){ if(f)mc=max(cur+1,mc);cur=0;}
            else if(f) cur++;
            if(n%2) f=1;
            n/=2;
        }
        return mc;
    }
};