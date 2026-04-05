// Last updated: 4/5/2026, 11:45:16 AM
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int>ans;
        int c=0;
        for(int i=0;i<jewels.size();i++){
            ans[jewels[i]]++;
        }
        for(int i=0;i<stones.size();i++){
            if(ans[stones[i]]!=0) c++;
        }
        return c;
    }
};