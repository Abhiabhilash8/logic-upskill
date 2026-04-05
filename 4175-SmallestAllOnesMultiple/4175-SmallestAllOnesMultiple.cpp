// Last updated: 4/5/2026, 11:41:19 AM
class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2==0 || k%5==0) return -1;
        long long mul=1;
        long long var=1;
        for(int i=0;i<1e7-1 && mul<=k;i++){
            
            var=(var*10+1)%k;
            mul++;
            if(var==0) {
                return mul;}
            
        }
        return -1;
    }
};