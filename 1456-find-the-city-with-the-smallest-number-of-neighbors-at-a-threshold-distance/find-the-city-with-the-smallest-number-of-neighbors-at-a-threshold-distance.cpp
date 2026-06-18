class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        vector<vector<int>>adj(n , vector<int>(n , 10005));
        for(auto &e: edges){
            adj[e[0]][e[1]] = e[2];
            adj[e[1]][e[0]] = e[2];
        }
        for(int i = 0; i<n ;i++) adj[i][i] = 0;

        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
                }
            }
        }

        pair<int,int>ans = {-1 , INT_MAX};
        for(int i = 0; i<n; i++){
            int c = 0;
            for(int j = 0; j<n; j++) c += (th >= adj[i][j]);
            if(c <= ans.second){
                ans = {i , c};
            }
        }

        return ans.first;


    }
};