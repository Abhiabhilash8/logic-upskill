// Last updated: 4/5/2026, 11:45:08 AM
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>>g(graph.size());
        vector<int>indeg(graph.size(),0),ans;
        for(int i=0;i<graph.size();i++){
            for(auto it: graph[i]){
                g[it].push_back(i);
                indeg[i]++;
            }
        }

        queue<int>q;
        for(int i=0;i<g.size();i++){
            if(indeg[i]==0) q.push(i);
        }

        while(q.size()){
            int ele=q.front();
            q.pop();
            ans.push_back(ele);
            for(auto it: g[ele]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }

        sort(ans.begin(),ans.end());
        return ans;

    }
};