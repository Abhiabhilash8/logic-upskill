class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& con) {
        if(con.size() < n - 1) return -1;
        vector<bool>vis(n , false);
        vector<vector<int>>adj(n);;
        for(auto &e: con){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = 0;
        for(int i = 0; i<n; i++){
            if(vis[i]) continue;
            ans++;
            queue<int>q;
            q.push(i);
            vis[i] = 1;
            while(q.size()){
                int out = q.front();
                q.pop();
                for(auto node: adj[out]){
                    if(!vis[node]) {vis[node] = 1; q.push(node);}
                }
            }
        }

        return ans - 1;

    }
};