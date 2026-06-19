class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int cs = 0;
        for(auto g: gain){
            cs += g;
            ans = max(ans , cs);
        }
        return ans;
    }
};