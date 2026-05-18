class Solution {
public:  

    bool same(int source, int target, vector<vector<pair<int,int>>>&adj){
        vector<bool>vis(1e3+1 , false);
        queue<int>q;
        q.push(source);
        vis[source] = 1;
        while(q.size()){
            int u = q.front();
            q.pop();
            if(u == target) return 1;
            for(auto e: adj[u]){
                if(!vis[e.first]){
                    q.push(e.first);
                    vis[e.first] = 1;
                }
            }
        }

        return false;
    }

    bool check(vector<vector<pair<int,int>>>&adj , int th, int source , int target , int k){
        vector<int>dist(1001 , 1001);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        pq.push({0,source});
        dist[source] = 0;
        while(pq.size()){
            int load = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(dist[u] < load) continue;

            for(auto e: adj[u]){
                int v = e.first, wt = e.second;
                if(dist[v] > load + (wt>th)){
                    dist[v] = load + (wt>th);
                    pq.push({dist[v] , v});
                }
            }
            
        }

        return dist[target]<=k;

    }

    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto e: edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }

        if(!same(source, target, adj)) return -1;
        int l = -1, r = 1e9+1;
        while(r-l>1){
            int m = l + (r-l)/2;
            if(check(adj , m , source , target , k)) r=m;
            else l=m;
        }

        return r;
        
    }
};