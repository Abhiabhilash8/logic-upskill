// Last updated: 4/5/2026, 11:47:39 AM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>ps(n);
        int s=0;
        for(int i=n-1;i>=0;i--){
            s=max(s,prices[i]);
            ps[i]=s;
        }


        int ma=0;
        for(int i=0;i<n-1;i++){
            ma=max(ma,-prices[i]+ps[i+1]);
        }

        return ma;
        
    }
};