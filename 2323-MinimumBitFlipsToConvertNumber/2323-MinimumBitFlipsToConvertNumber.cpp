// Last updated: 4/5/2026, 11:43:27 AM
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp=start^goal;
        int ans=0;
        for(int i=0;i<32;i++){
            if(temp&(1<<i)) ans++;
        }
        return ans;
    }
};