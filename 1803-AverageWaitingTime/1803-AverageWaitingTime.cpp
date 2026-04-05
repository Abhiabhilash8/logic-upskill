// Last updated: 4/5/2026, 11:44:01 AM
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long wt=0,ile=0;
        for(auto it: customers){
            long long st=it[0],req=it[1];
            if(st<ile)wt+=(ile-st);
            wt+=req;
            ile=max(ile,st);
            ile=ile+req;
        }

        return (double)wt/customers.size();
    }
};