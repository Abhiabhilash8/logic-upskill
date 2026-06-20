class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy = INT_MAX , p = 0 , ans = 0;
        for(int i = 0; i<n; i++){
            if(prices[i] < buy){
                buy = prices[i];
            }else{
                ans += prices[i] - buy;
                buy = prices[i];
            }
        }

        return ans;
    }
};