class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int s = 0;

        sort(cost.begin() , cost.end());

        for(int i = cost.size() - 1; i >= 0 ; i -= 3){
            if(i == 0) return s + cost[i];
            s += cost[i] + cost[i-1];
        }


        return s;
    }
};