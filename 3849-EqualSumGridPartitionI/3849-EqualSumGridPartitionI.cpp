// Last updated: 4/5/2026, 11:42:39 AM
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long n=grid.size(),m=grid[0].size(),cs=0;
        vector<long long>h(n,0),v(m,0);
        for(int i=0;i<n;i++){
            long long s=0;
            for(int j=0;j<m;j++) s+=grid[i][j];
            h[i]=s;
        }
        for(int j=0;j<m;j++){
            long long s=0;
            for(int i=0;i<n;i++){
                s+=grid[i][j];
                cs+=grid[i][j];
            }
            v[j]=s;
        }

        if(cs&1) return false;

        long long yo=0;
        for(int i=0;i<m;i++){
            yo+=v[i];
            if(yo==cs/2) return true;
        }
        yo=0;
        for(int i=0;i<n;i++){
            yo+=h[i];
            if(yo==cs/2) return true;
        }

        return false;



    }
};