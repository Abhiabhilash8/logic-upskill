// Last updated: 4/5/2026, 11:42:57 AM
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<pair<int,int>>>ps(n,vector<pair<int,int>>(m,{0,0}));
       
        
        int ans=0;
        for(int i=0;i<n;i++){
            vector<pair<int,int>>v(m,{0,0});
            for(int j=0;j<m;j++){
                if(j>0) v[j]=v[j-1];
                if(grid[i][j]=='X') v[j].first++;
                else if(grid[i][j]=='Y') v[j].second++;
                if(i>=1) ps[i][j]=ps[i-1][j];
                ps[i][j].first+=v[j].first,ps[i][j].second+=v[j].second;
                if(ps[i][j].first==ps[i][j].second && ps[i][j].first) ans+=1;
            }
        }



        return ans;
    }
};