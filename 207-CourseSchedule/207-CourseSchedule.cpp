// Last updated: 4/5/2026, 11:46:57 AM
class Solution {
public:

bool dfs(int node,vector<vector<int>>&graph,vector<int>&vis,vector<int>&pathvis){
        vis[node]=1;
        bool x=true;
        for(auto ele: graph[node]){
            if(pathvis[ele]) return false;
            pathvis[ele]=1;
            if(!vis[ele]) x&=dfs(ele,graph,vis,pathvis);
            pathvis[ele]=0;
        }
        return x;
    }
    bool canFinish(int n, vector<vector<int>>& req) {
        vector<vector<int>>graph(n);
        for(int i=0;i<req.size();i++){
            graph[req[i][1]].push_back(req[i][0]);
        }

        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                vector<int>pathvis(n,0);
                pathvis[i]=1;
                if(!dfs(i,graph,vis,pathvis)) return false;
            }
        }

        return true;


    }
};