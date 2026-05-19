class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int ans = abs(goal);
        vector<int>ps;
        ps.push_back(0);
        int n = nums.size();
        for(int i = 0; i<n/2 ; i++){
            int k = ps.size();
            for(int j = 0; j<k;j++){
                ps.push_back(ps[j] + nums[i]);
                ans = min(ans , abs(goal - ps[j] - nums[i]));
            }
        }

        sort(ps.begin() , ps.end());


        vector<int>post;
        post.push_back(0);
        for(int i = n/2; i<n ; i++){
            int k = post.size();
            for(int j = 0; j<k;j++){
                post.push_back(post[j] + nums[i]);
                int ind = upper_bound(ps.begin() ,ps.end() , goal - post[j] - nums[i]) - ps.begin();
                if(ind>=0 && ind<ps.size()) ans = min(ans , abs(goal - ps[ind] - post[j] - nums[i]));
                if(ind-1>=0 && ind-1<ps.size()) ans = min(ans , abs(goal - ps[ind-1] - post[j] - nums[i]));
            }
        }

        return ans;
    }
};