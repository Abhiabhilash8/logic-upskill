// Last updated: 4/5/2026, 11:48:23 AM
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int>dp(grid[0].size(),-1);


        for(int i=0;i<grid.size();i++){
            vector<int>temp(grid[0].size(),-1);
            for(int j=0;j<grid[0].size();j++){
                int left=-1,top=-1;
                if(j>0) left=grid[i][j]+temp[j-1];
                if(i>0) top=grid[i][j]+dp[j];
                if(left==-1&&top==-1) temp[j]=grid[0][0];
                else if(left==-1) temp[j]=top;
                else if(top==-1) temp[j]=left;
                else temp[j]=min(left,top);
            }

            dp=temp;
        }

        return dp[grid[0].size()-1];
    }
};