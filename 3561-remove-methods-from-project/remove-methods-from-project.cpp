class Solution {
public:

    void dfs(int u , vector<int>&state , vector<vector<int>>&adj){
        if(state[u] == 1) return;
        state[u] = 1;
        for(auto v: adj[u]){
            if(!state[v]) dfs(v , state , adj);
        }
    }

    void dfs2(int u , vector<int>&state ,  vector<vector<int>>&adj){
        if(state[u] == -1) return;
        state[u] = -1;
        for(auto v: adj[u]){
            if(state[v] != -1) dfs2(v , state , adj);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& ed) {
        vector<int>state(n , 0);
        vector<vector<int>>adj(n);
        for(auto &v: ed){
            adj[v[0]].push_back(v[1]);
        }


        int c = 0;
        dfs(k , state , adj);
        for(int i = 0; i<n; i++) c += state[i];

        for(int u = 0; u < n; u++){
            if(state[u] == 0) dfs2(u , state , adj);
        }

        for(int i = 0; i<n; i++) if(state[i] == 1) c--;
        if(c != 0) for(int i = 0; i<n; i++) state[i] = -1; 

        vector<int>ans;
        for(int i = 0; i<n; i++){
            if(state[i] == -1) ans.push_back(i);
        }

        return ans;

    }
};