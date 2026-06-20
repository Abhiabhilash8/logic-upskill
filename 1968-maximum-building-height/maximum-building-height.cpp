class Solution {
public:
    int maxBuilding(int N, vector<vector<int>>& r) {

        r.push_back({1,0});
        r.push_back({N , N-1});
        sort(r.begin() , r.end());

        int ans = 0 , n = r.size();
        for(int i = 1; i<r.size() ; i++) r[i][1] = min(r[i][1] , r[i-1][1] + r[i][0] - r[i-1][0]);
        for(int i = n-2; i >= 0 ; i--) r[i][1] = min(r[i][1] , r[i + 1][1] + r[i + 1][0] - r[i][0]);


        for(int i = 1; i < n; i++)
            ans = max(ans , max( r[i][1] , r[i-1][1] ) + (abs(r[i][0] - r[i-1][0]) - abs( r[i][1] - r[i-1][1] ))/2 );

            return ans;
        

    }
};