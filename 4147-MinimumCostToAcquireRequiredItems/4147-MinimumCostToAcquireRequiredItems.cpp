// Last updated: 4/5/2026, 11:41:31 AM
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
        if(cost1+cost2>=costBoth){
            int mini=min(need1,need2);
            ans+=(1LL*mini*costBoth);
            need1-=mini;
            need2-=mini;
        }
        if(need1>0){
            int cost=min(cost1,costBoth);
            ans+=1LL*need1*cost;
            if(cost==costBoth) need2-=need1;
        }
        if(need2>0){
            int cost=min(cost2,costBoth);
            ans+=1LL*need2*cost;
        }

        return ans;
    }
};