// Last updated: 4/5/2026, 11:42:29 AM
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1],w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }

        vector<int>dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        dist[0]=0;
        while(pq.size()){
            int d=pq.top().first,node=pq.top().second;
            pq.pop();
            for(auto [e,w]: adj[node]){
                if(d+w<dist[e]){
                    dist[e]=d+w;
                    pq.push({d+w,e});
                }
            }
        }
        if(dist[n-1]==INT_MAX) return -1;

        return dist[n-1];
    }
};