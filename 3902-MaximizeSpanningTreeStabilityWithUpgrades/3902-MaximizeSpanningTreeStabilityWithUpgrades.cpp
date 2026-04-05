// Last updated: 4/5/2026, 11:42:28 AM
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    bool Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return false;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }

        return true;
    }
};

class Solution {
public:

    bool c(long long m,vector<vector<int>>& edges,long long k,int n){
        DSU dsu(n);
        vector<vector<int>>pen;
        for(auto &ed: edges){
            int u=ed[0],v=ed[1],s=ed[2],must=ed[3];

            if(must){
                if(s<m) return false;
                dsu.Union(u , v);
            }
            else{
                if(s>=m){
                    dsu.Union(u,v);
                }else if(2*s>=m){
                     pen.push_back({u,v});
                }
            }
        }

        for(auto &ed: pen){
            int u=ed[0],v=ed[1];

            if(dsu.find(u)!=dsu.find(v)){
                if(k<=0) return false;
                k--;
                dsu.Union(u,v);
            }
        }

        int root=dsu.find(0);
        for(int node=1;node<n;node++){
            if(root!=dsu.find(node)) return false;
        }
        return true;

    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        // check for cycle
        DSU dsu(n);
        for(auto &ed: edges){
            int u=ed[0],v=ed[1],s=ed[2],must=ed[3];

            if(must){
                if(dsu.find(u)==dsu.find(v)) return -1;
                dsu.Union(u,v);
            }
        }


        long long l=0,r=2e5+1,res=-1;
        while(r-l>1){
            long long m=l+(r-l)/2;

            if(c(m,edges,k,n)){
                l=m;
                res=l;
            }
            else r=m;
        }

        return res;
    }
};