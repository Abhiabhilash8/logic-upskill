class Solution {
public:

    bool check(long long min_edge , vector<vector<pair<int,int>>>&adj , long long k){
        int n = adj.size();
        priority_queue<
            pair<long long , int>,
            vector<pair<long long , int>>,
            greater<pair<long long , int>>
        >pq;

        vector<long long>dist(adj.size() , LLONG_MAX);
        dist[0] = 0;
        pq.push({0 , 0});
        while(!pq.empty()){
            long long d = pq.top().first , node = pq.top().second;
            pq.pop();
            if(d > dist[node]) continue;

            for(auto &[nb , w]: adj[node]){
                if(w < min_edge || d + w > k) continue;

                if(dist[nb] > d + w){
                    dist[nb] = d + w;
                    pq.push({d + w , nb});
                }

            }
        }


        return dist[n-1] != LLONG_MAX;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>>adj(n);
        for(auto e: edges){
            if(!online[e[0]] || !online[e[1]]) continue;
            adj[e[0]].push_back({e[1] , e[2]});
        }

        long long l = 0 , h = 1000000005;
        if(!check(l , adj , k)) return -1;

        while(h - l > 1){
            long long m = l + (h - l) / 2;
            if(check(m , adj , k)) l = m;
            else h = m;
        }

        return l;
    }
};