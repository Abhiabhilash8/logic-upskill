class Solution {
public:
    int minOperations(vector<vector<int>>& g, int x) {
        if(g.size() == g[0].size() && g[0].size()==1) return 0;
        vector<int>v;
        for(int i=0;i<g.size();i++) for(int j=0;j<g[0].size();j++) v.push_back(g[i][j]);
        sort(v.begin() , v.end());
        int n = v.size();
        int ans = 0;

        int md = v[n/2];
        for(int i = 0;i < n; i++){
            int k = abs(md - v[i]);
            if(k%x != 0) return -1;
            ans += k/x;
        }

        return ans;
    }
};