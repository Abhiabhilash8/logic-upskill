class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }

        vector<int>ans;
        for(auto q: queries){
            int x=nums[q];
            
            vector<int>&v=mpp[nums[q]];
            if(v.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int i = lower_bound(v.begin() , v.end() , q) - v.begin();


            int res=INT_MAX;
            int l = v[(i - 1 + v.size()) % v.size()];
            int dl = abs(q - l);
            res = min({ res, dl , n-dl});

            int r = v[( i + 1 ) % v.size()];
            int dr = abs( q - r );

            res = min({ res , dr , n-dr });

            ans.push_back(res);
        }

        return ans;
    }
};