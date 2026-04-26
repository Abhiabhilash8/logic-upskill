class Solution {
public:

    bool explore(int i , int j , vector<vector<char>>&grid , vector<vector<bool>>&vis , char need , int pi , int pj){
        int n=grid.size() , m=grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m ) return false;
        if(grid[i][j] != need) return 0;
        if(vis[i][j]) return true;
        vis[i][j] = 1;
        bool x = false;
        int di[] = {0,1,0,-1},dj[] = {1,0,-1,0};
        for(int k = 0 ; k<4 ; k++){
            if(!((pi == di[k] + i) && (pj == dj[k] + j))) x |= explore(i+di[k],j+dj[k],grid,vis,need,i,j);
        }

        return x;

    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        bool chee = 0;
        for(int i = 0;i<n; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j]) chee |= explore(i,j,grid,vis,grid[i][j],-1,-1);
            }
        }

        return chee;
    }
};