// Last updated: 4/5/2026, 11:45:12 AM
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // k=k+1;
        vector<vector<pair<int,int>>>adj(n);
        // adj making
        for(auto f: flights){
            int s=f[0],t=f[1],p=f[2];
            adj[s].push_back({t,p});
        }
        vector<int>prices(n,INT_MAX);
        // prices contain min price to reach that particular ap

        // priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        queue<vector<int>>pq;
        pq.push({0,0,src});
        // pq contains price,stops taken,node
        prices[src]=0;

        while(pq.size()){
            int p=pq.front()[0],s=pq.front()[1],node=pq.front()[2];
            pq.pop();
            if(s>k) continue;

            for(auto [ele,paisal]: adj[node]){
                if((prices[ele]>p+paisal) && s<=k ){
                   prices[ele]=p+paisal;
                pq.push({prices[ele],s+1,ele});
                }
            }
        }

        if(prices[dst]==INT_MAX) return -1;
        return prices[dst];


    }
};