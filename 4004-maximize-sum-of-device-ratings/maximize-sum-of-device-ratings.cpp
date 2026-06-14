class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        long long s = 0,mi=INT_MAX;
        for(auto &u: units){
            sort(u.begin() , u.end());
            s += u.size() > 1? u[1]: u[0];
            mi = min((int)mi , u[0] );
        } 

        long long ans = INT_MIN;

        for(auto &u: units) ans = max(ans , s - (u.size() > 1? u[1]: u[0]) + mi);


        return ans;
    }
};