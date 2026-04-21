/*
Disjoint Set Union with path compression + union by rank.
Complexity: O(α(n)) ≈ O(1) amortised per operation.

Usage:
  DSU dsu(n);
  dsu.find(x)     — root/representative of x
  dsu.Union(x, y) — merge sets; returns false if already same set

Example:
  DSU dsu(5);       // {0} {1} {2} {3} {4}
  dsu.Union(0,1);   // {0,1} {2} {3} {4}
  dsu.Union(1,2);   // {0,1,2} {3} {4}
  dsu.find(0)==dsu.find(2) → true   (same set)
  dsu.find(0)==dsu.find(3) → false  (different sets)
  dsu.Union(0,2)           → false  (already in same set)

*/
class DSU{
public:
    vector<int> parent, rank_;
    DSU(int n){
        parent.resize(n); rank_.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    // Path compression
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    // Union by rank — returns false if already in same set
    bool Union(int x, int y){
        int xp=find(x), yp=find(y);
        if(xp==yp) return false;
        if(rank_[xp]>rank_[yp])      parent[yp]=xp;
        else if(rank_[xp]<rank_[yp]) parent[xp]=yp;
        else{ parent[xp]=yp; rank_[yp]++; }
        return true;
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& as) {
        int n = target.size();
        DSU dsu(n+1);
        for(auto it: as){
            dsu.Union(it[0] , it[1]);
        }

        unordered_map<int,unordered_map<int,int>>mpp;
        for(int i=0;i<n;i++){
            mpp[dsu.find(i)][source[i]]++;
            mpp[dsu.find(i)][target[i]]--;
        }


        int ans = 0;
        for(auto &it: mpp){
            for(auto &sairam: it.second){
                ans += abs(sairam.second);
            }
        }

        return ans/2;
    }
};