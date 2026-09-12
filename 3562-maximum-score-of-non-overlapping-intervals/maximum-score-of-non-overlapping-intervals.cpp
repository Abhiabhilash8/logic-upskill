class Solution {
public:
    #define ll long long
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        for(int i = 0; i < n; i++) intervals[i].push_back(i);
        sort(intervals.begin() , intervals.end());
        vector<vector<pair<ll, vector<int>>>>dp(n + 1 , vector<pair<ll, vector<int>>>(5 , {0 , {}}));

        vector<int>st;
        for(auto &it: intervals) st.push_back(it[0]);

        for(int i = n - 1; i >= 0; i--){
            for(int picks = 4; picks >= 1; picks--){
                dp[i][picks] = dp[i + 1][picks];
                int next_ind = upper_bound(st.begin() , st.end() , intervals[i][1]) - st.begin();
                auto take = dp[next_ind][picks - 1];
                take.first += intervals[i][2];
                take.second.push_back(intervals[i][3]); 
                sort(take.second.begin(), take.second.end());
                
                if(take.first > dp[i][picks].first || (take.first == dp[i][picks].first && take.second < dp[i][picks].second)) {
                    dp[i][picks] = take;
                }
            }
        }
        return dp[0][4].second;
    }
};