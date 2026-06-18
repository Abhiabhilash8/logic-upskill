class Solution {
public:

    int findParent(int node , vector<int>&parent){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node] , parent);
    }

    void unionNodes(int u , int v , vector<int>&parent , vector<int>&size){
        int rootU = findParent(u , parent);
        int rootV = findParent(v , parent);
        if(rootU != rootV){
            if(size[rootU] < size[rootV]){
                parent[rootU] = rootV;
                size[rootV] += size[rootU];
            }else{
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& ac) {
        int n = ac.size();
        vector<int>parent(n) , size(n , 1);
        for(int i = 0; i<n; i++) parent[i] = i;
        unordered_map<string , int> mpp;
        for(int i = 0; i<n; i++){
            for(int j =  1; j<ac[i].size(); j++){
                if(mpp.find(ac[i][j]) == mpp.end()){
                    mpp[ac[i][j]] = i;
                }else{
                    unionNodes(i , mpp[ac[i][j]] , parent , size);
                }
            }
        }

        unordered_map<int , vector<string>> merged;
        for(auto &it: mpp){
            int root = findParent(it.second , parent);
            merged[root].push_back(it.first);
        }

        vector<vector<string>>ans;
        for(auto &it: merged){
            vector<string>t = it.second;
            sort(t.begin() , t.end());
            t.insert(t.begin() , ac[it.first][0]);
            ans.push_back(t);
        }

        return ans;
    }
};