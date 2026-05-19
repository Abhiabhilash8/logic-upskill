class Solution {
public:


    void f(int i , vector<int>&nums , vector<vector<int>>&ps , int cs , int picks , int hn , int ts){
        if(i == hn){
            ps[picks].push_back(cs);
            return;
        }
        if(i >= hn)  return;

        f(i+1 , nums , ps , cs , picks , hn , ts);
        f(i+1 , nums , ps , cs + nums[i] , picks+1 , hn , ts);
    }

    int minimumDifference(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        vector<vector<int>>ps(n),rs(n);
        int hn = n/2;
        int ts = accumulate(nums.begin() , nums.end() , 0 );
        f(0 , nums , ps , 0 , 0 , hn , ts);
        f(hn , nums , rs , 0 , 0 , n , ts);

        for(int i =0; i<ps.size(); i++) sort(ps[i].begin() , ps[i].end());

        for(int i = 0; i<rs.size(); i++){
            for(int j = 0; j<rs[i].size(); j++){
                int ind = lower_bound(ps[hn - i].begin() , ps[hn - i].end() , ts/2 -  rs[i][j]) - ps[hn - i].begin();
                if(ind >=0 && ind<ps[hn - i].size()) ans = min(ans , abs(ts - 2*(ps[hn - i][ind] + rs[i][j])));
                if(ind - 1 >=0 && ind - 1<ps[hn - i].size()) ans = min(ans , abs(ts - 2*(ps[hn - i][ind - 1] + rs[i][j])));
            }
        }

        return ans;
    }
};
