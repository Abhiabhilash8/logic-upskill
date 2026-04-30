class Solution {
public:

    int f(int i,int j,int k,auto &grid,auto &dp){
        if(k<0) return -1;
        if(dp[i][j][k]!=-2) return dp[i][j][k];

        int right=-1,down=-1;
        if(j<grid[0].size()-1) {
            if(grid[i][j+1]) right=f(i,j+1,k-1,grid,dp);
            else right=f(i,j+1,k,grid,dp);
        }
        if(i<grid.size()-1){
            if(grid[i+1][j]) down=f(i+1,j,k-1,grid,dp);
            else down=f(i+1,j,k,grid,dp);
        }
        if(i==grid.size()-1 && j==grid[0].size()-1) return dp[i][j][k]=grid[i][j];

        // cout<<down<<" is down and right "<<right<<"\n";

        if(down==-1&&right==-1) return dp[i][j][k]=-1;
        else if(down==-1) return dp[i][j][k]=right+grid[i][j];
        else if(right==-1) return dp[i][j][k]=down+grid[i][j];

        return dp[i][j][k]=grid[i][j]+max(down,right);
    }
    
    int maxPathScore(vector<vector<int>>& grid, int k) {

        vector<vector<vector<int>>>dp(grid.size()+1,vector<vector<int>>(grid[0].size()+1,vector<int>(1001,-2)));
        


        return f(0,0,k,grid,dp);
    }
};