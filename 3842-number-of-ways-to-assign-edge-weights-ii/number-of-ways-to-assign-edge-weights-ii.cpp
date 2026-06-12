class Solution {
public:

 typedef long long ll;
 #define M 1000000007

    ll binexp(ll a,ll b,ll mod2=M){
        if(b < 0) return 0;
        ll res=1;a%=mod2;
        while(b){
            if(b%2) res=(res*a)%mod2;
            a=(a*a)%mod2;
            b>>=1;
        }
        return res;
    }

    void dfs(int v , int u , vector<vector<int>>&adj , int dist[100001] , int up[][32]){
        dist[v] = dist[u] + 1;
        up[v][0] = u;
        for(auto n: adj[v]){
            if(n != u) dfs(n , v , adj , dist , up);
        }
    }


    int lift(int node , int distance , int up[][32]){
        int k = 0;
        while(distance){
            if(distance & 1){
                node = up[node][k];
            }
            distance/=2;
            k++;
        }

        return node;
    }

    int findlca(int u , int v , int up[][32]){
        if(u == v) return u;
        int node = 1;
        for(int i = 19; i>=0; i--) {
            if(up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }


    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        /*
            1. make the dist for every node from root
            2. find the difference dist
            3. find lca
            4. ans = dist[u] + dist[v] -  2*dist[lca]
        */
        
        // make adjacency list
        int n = edges.size() + 1;
        vector<vector<int>>adj(1e5 + 1);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // making bin lift table
        int up[100001][32];
        memset(up , -1 , sizeof(up));

        // make dist table
        int dist[100001] = {0};
        dist[0] = -1;
        dfs(1 , 0 , adj , dist , up);

        for(int k = 1; k<20; k++){
            for(int node = 1; node <= n; node++){
                if(up[node][k-1] != -1) up[node][k] = up[up[node][k-1]][k-1];
            }
        }

        vector<int>ans;

        // queries
        for(auto q: queries){
            int u = q[0] , v = q[1];
            if(dist[u] < dist[v]) swap(u , v);

            int equivalent_node = lift(u , dist[u] - dist[v] , up);

            int lca = findlca(equivalent_node , v , up);

            ans.push_back(binexp(2 , dist[u] + dist[v] - 2*dist[lca] - 1 ));
        }

        return ans;
    }
};