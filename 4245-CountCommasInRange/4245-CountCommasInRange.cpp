// Last updated: 4/5/2026, 11:40:56 AM
class Solution {
public:
    int countCommas(int n) {
        int ans=0;
        if(n<=999) ans=0;
        else ans=n-1000+1;
        
        return ans;
        
    }
};