// Last updated: 4/5/2026, 11:45:22 AM
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        vector<int>dist(n,INT_MAX);
        for(auto it: times){
            adj[it[0]-1].push_back({it[1]-1,it[2]});
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(k-1);
        dist[k-1]=0;
        while(pq.size()){
            // int d=pq.top().first,node=pq.top().second;
            int node=pq.top();
            pq.pop();

            for(auto [ele,ew]: adj[node]){
                if(dist[node]+ew<dist[ele]){
                    dist[ele]=dist[node]+ew;
                    pq.push(ele);
                }
            }
        }

        int ans= *max_element(dist.begin(),dist.end());
        if(ans==INT_MAX) return -1;
        else return ans;

    }
};