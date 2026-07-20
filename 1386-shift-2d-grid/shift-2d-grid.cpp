class Solution {
public:
    int n , m;
    void sh(vector<vector<int>>&g){
        vector<int>v(n);
        
        for(int i=0;i<n; i++) v[i] = g[i][m-1];

        for(int j = 0; j<m; j++)
            for(int i = 0; i<n; i++)
                swap(v[i] , g[i][j]);


        for(int i = 1; i<n; i++) g[i][0] = v[i-1];

        g[0][0] = v[n-1];
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& g, int k) {
        n = g.size() , m = g[0].size();
        cout<<k<<endl;
        while(k--) sh(g);
        return g;
    }
};