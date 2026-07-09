class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int md, vector<vector<int>>& q) {
        vector<int>par(n);
        int parent = n-1;
        par[n-1] = n-1;

        for(int i = n-2; i>=0;i--){
            if(nums[i+1] - nums[i] > md) parent = i;
            par[i] = parent;
        }


        vector<bool>a;

        for(int i = 0; i<q.size(); i++){
            if(q[i][0] > q[i][1]) swap(q[i][0] , q[i][1]);
            a.push_back(par[q[i][0]] >= q[i][1]);
        }

        return a;
    }
};