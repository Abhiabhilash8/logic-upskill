class Solution {
public:
    static constexpr int M = 1000000007;
    int zigZagArrays(int n, int l, int r) {
        r = r - l;
        l = 0;
        
        vector<vector<int>>prev(r + 5, vector<int>(2));
        vector<vector<int>>cur(r + 5, vector<int>(2));
        for(int i = l; i<=r; i++){ prev[i][1] = 1;prev[i][0] = 1;}

        for(int i = n-2; i>=0; i--){
            cur[l][1] = 0 , cur[r][0] = 0;
            for(int x = l + 1; x<=r; x++) cur[x][1] = (cur[x-1][1]%M + prev[x-1][0]%M)%M;
            for(int x = r - 1; x >= l; x--) cur[x][0] = (cur[x+1][0]%M + prev[x+1][1]%M)%M;

            swap(prev, cur);
        }

        int s = 0;
        for(int x = l; x <= r; x++){
            s = (s%M + prev[x][0]%M)%M;
            s = (s%M + prev[x][1]%M)%M;
        }

        return s;
    }
};