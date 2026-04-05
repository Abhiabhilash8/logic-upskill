// Last updated: 4/5/2026, 11:45:13 AM
class Solution {
public:

    bool  dfs(int node,vector<vector<int>>& graph,vector<int>&vis,int c){
        bool x=true;
        for(auto i: graph[node]){
            if(!vis[i]){
                vis[i]=c;
                x&=dfs(i,graph,vis,(c==2)?1:2);
            }else if(c!=vis[i]) return false;
        }
        return x;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>vis(100,0);
        bool x=true;
        for(int i=0;i<graph.size();i++){
            
            if(graph[i].size() && !vis[i]){
                vis[0]=1;
                 x&= dfs(i,graph,vis,2);
            }
        }
        return x;
        
    }
};