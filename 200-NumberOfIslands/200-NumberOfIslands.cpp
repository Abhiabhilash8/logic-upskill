// Last updated: 4/5/2026, 11:47:06 AM
class Solution {
public:
    void trav(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& v){

        if(i<0 || j>=grid[0].size() || i>=grid.size() || j<0 || grid[i][j]=='0' || v[i][j]) return;
        else{
            v[i][j]=1;
            trav(i,j+1,grid,v);
            trav(i+1,j,grid,v);
            trav(i,j-1,grid,v);
            trav(i-1,j,grid,v);
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        vector<vector<int>>v(grid.size(),vector<int>(grid[0].size(),0));

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !v[i][j]){
                    trav(i,j,grid,v);
                    ans++;
                }
            }
        }


        return ans;
    }
};