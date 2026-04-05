// Last updated: 4/5/2026, 11:43:05 AM
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>ps(n,vector<int>(m,0));
       

        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>v(m,0);
            for(int j=0;j<m;j++){
                if(j>0) v[j]=v[j-1];
                v[j]+=grid[i][j];
                if(i>=1) ps[i][j]=ps[i-1][j];
                ps[i][j]+=v[j];
                if(ps[i][j]<=k) ans+=1;
            }
        }



        return ans;
    }
};