class Solution {
public:

    int dfs(int i , int j , vector<vector<int>>&g , vector<vector<int>>&id , int cid){
        if(i < 0 || j < 0 || i>= g.size() || j >= g[0].size() || !g[i][j] || id[i][j] != -1) return 0;

        id[i][j] = cid;
        return 1 + dfs(1 + i , j , g , id , cid) + dfs( i , j + 1 , g , id , cid) + dfs(i - 1 , j , g , id , cid) + dfs(i , j - 1, g , id , cid);
    }

    int largestIsland(vector<vector<int>>& g) {
        int n = g.size() , m = g[0].size();
        vector<vector<int>>id(n , vector<int>(m , -1));
        vector<int>size(n * m + 1 , 0);
        int cid = 1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(g[i][j] && id[i][j] == -1){
                    size[cid] = dfs(i , j , g , id , cid);
                    cid++;
                }
            }
        }
        int ans = -1;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!g[i][j]){
                    unordered_set<int>st;
                    if(i > 0 && g[i - 1][j]) st.insert(id[i-1][j]);
                    if(j > 0 && g[i][j - 1]) st.insert(id[i][j - 1]);
                    if(i < n-1 && g[i + 1][j]) st.insert(id[i + 1][j]);
                    if(j < m-1 && g[i][j + 1]) st.insert(id[i][j + 1]);

                    int ka = 1;
                    for(auto x: st) ka += size[x]; 
                    ans = max(ans , ka);
                }
            }
        }


        return ans == -1 ? n * m : ans;
    }
};