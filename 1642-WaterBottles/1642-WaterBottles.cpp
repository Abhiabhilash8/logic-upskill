// Last updated: 4/5/2026, 11:44:17 AM
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0,empty=0;
        int n=0;
        while(numBottles){
            ans+=numBottles;
            n=numBottles+empty;
            numBottles=(numBottles+empty)/numExchange;
            empty=n%numExchange;

        }

        return ans;
    }
};