class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // pq -> least edge , node, dist[node]  -> least edge weight to reach node
        
        vector<vector<pair<int, int>>>adj(n + 1 );
        for(auto &v: roads){
            adj[v[0]].push_back({v[1] , v[2]});
            adj[v[1]].push_back({v[0] , v[2]});
        }

        priority_queue< pair<int , int>,
            vector<pair<int , int>>,
            greater<pair<int , int>>
        >pq;
        vector<int>dist(n + 1 , INT_MAX);
        pq.push({INT_MAX , 1});

        while(pq.size()){
            int prev = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(dist[u] < prev) continue;

            for(auto &[v , w]: adj[u]){
                int thop = min(w , prev);
                if(dist[v] > thop){
                    dist[v] = thop;
                    pq.push({thop , v});
                }
            }
        }


        return dist[n];
        
    }
};