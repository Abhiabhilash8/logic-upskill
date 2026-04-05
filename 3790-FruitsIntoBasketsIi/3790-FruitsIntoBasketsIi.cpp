// Last updated: 4/5/2026, 11:42:42 AM
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int c=0,n=fruits.size();
        for(int i=0;i<n;i++){
            int f=0;
            for(int j=0;j<n;j++){
                if(baskets[j]>=fruits[i]){
                    baskets[j]=-1;
                    f=1;
                    break;
                }
            }
            if(!f) c++;
        }

        return c;
    }
};