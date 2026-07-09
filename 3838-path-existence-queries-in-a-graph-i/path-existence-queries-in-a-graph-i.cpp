class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int md, vector<vector<int>>& q) {
        vector<int>par(n);
        for(int i = 0; i<n; i++) par[i] = i;
        for(int i = n-2; i>=0;i--){
            int mk = upper_bound(nums.begin() , nums.end() , nums[i] + md) - nums.begin() - 1;
            par[i] = par[mk];
        }


        vector<bool>a;

        for(int i = 0; i<q.size(); i++){
            if(q[i][0] > q[i][1]) swap(q[i][0] , q[i][1]);
            a.push_back(par[q[i][0]] >= q[i][1]);
        }

        return a;
    }
};