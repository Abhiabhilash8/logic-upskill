// Last updated: 4/5/2026, 11:43:00 AM
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int mini=INT_MAX,minj=INT_MAX,maxi=-1,maxj=-1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    mini=min(mini,i);
                    maxi=max(maxi,i);
                    minj=min(minj,j);
                    maxj=max(maxj,j);
                }
            }
        }
        if(maxi==-1) return 0;
        else{
            return (maxi-mini+1)*(maxj-minj+1);
        }

    }
};