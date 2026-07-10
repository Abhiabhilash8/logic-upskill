constexpr int L = 18 , N = 1e5+1;
int up[L][N] , pos[N];
pair<int,int> xid[N];
class Solution {
public:

    int cnt(int u , int v , int L){
        if(u == v) return 0;
        if(up[0][u] >= v) return 1;
        if(up[L-1][u] < v) return -1;

        int step = 0;
        for(int j = L - 1; j >= 0; j--){
            if(up[j][u] < v){
                step += (1<<j);
                u = up[j][u];
            }
        }
        return step + 1;
    }

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int md, vector<vector<int>>& queries) {
        int maxL = bit_width((unsigned)n)+1;
        for(int i = 0; i<n; i++) xid[i] = {nums[i] , i};
        sort(xid , xid + n);
        for(int i  =0; i<n; i++) pos[xid[i].second] = i;

        for(int l = 0 , r = 0; l<n; l++){
            while(r+1 < n && xid[r+1].first - xid[l].first <= md) r++;
            up[0][l] = r;
        }

        for(int j = 1; j<maxL; j++){
            for(int i = 0; i<n; i++){
                up[j][i] = up[j-1][up[j-1][i]];
            }
        }

        vector<int>ans;
        for(auto &q: queries){
            auto [u , v] = minmax(pos[q[0]] , pos[q[1]]);
            ans.push_back(cnt(u , v, maxL));
        }

        return ans;

    }
};