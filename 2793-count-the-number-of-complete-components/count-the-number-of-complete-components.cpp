class Solution {
public:
    int c = 0;
    bool dfs(int u , vector<vector<int>>&adj , vector<bool>&vis , int tg){
        vis[u] = 1;
        bool k = (adj[u].size() == tg);
        for(auto v: adj[u]){
            if(!vis[v]) {
                vis[v] = 1;
                c++;
                k &= dfs(v , adj , vis , tg);
            }
        }

        return k;

    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = 0;
        vector<bool>vis(n , false);
        for(int i = 0; i<n; i++ , c = 0){
            if(!vis[i]){
                c++;
                ans += (dfs(i , adj , vis , adj[i].size()) && (c - 1 == adj[i].size()));
            }
        }

        return ans;
    }
};