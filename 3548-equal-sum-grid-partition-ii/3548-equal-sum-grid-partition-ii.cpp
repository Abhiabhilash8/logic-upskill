class Solution {
public:

    void makeg(vector<vector<int>>& grid2,vector<vector<int>>& grid,long long &t){
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid2[j][i]=grid[i][j];
                t+=grid[i][j];
            }
        }
    }

    void sw(vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        for(int j=0;j<m/2;j++){
            for(int i=0;i<n;i++){
                swap(grid[i][j],grid[i][m-j-1]);
            }
        }

    }

    bool hehe(vector<vector<int>>& grid,long long t){
        int n=grid.size(),m=grid[0].size();
        long long s=0;
        if(n==1){
            for(int j=0;j<m-1;j++){
                s+=grid[0][j];
                if((j>0 && (2*s-t)==grid[0][j]) || (2*s-t)==grid[0][0] || (2*s-t)==grid[0][m-1] || (2*s-t)==0) return true;
            }
            sw(grid);
            return false;
        }
        if(m==1){
            for(int i=0;i<n-1;i++){
                s+=grid[i][0];
                if( (i>0 && 2*s-t==grid[i][0]) || 2*s-t==grid[0][0] || 2*s-t==grid[n-1][m-1] || 2*s-t==0) return true;
            }
            sw(grid);
            return false;
        }

        set<int>st;
        st.insert(0);

        for(int j=0;j<m-1;j++){
            for(int i=0;i<n;i++){
                s+=grid[i][j];
                st.insert(grid[i][j]);
            }

            long long tg=2*s-t;
            if(j==0 || j==m-1){
                if((tg==grid[0][j] || tg==grid[n-1][j]) || tg==0) return true;
            }
            else if(tg>=0 && tg<=100000 && st.find(tg)!=st.end()) return true;
        }

        sw(grid);
        return false;

    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>grid2(m,vector<int>(n,0));
        long long t=0;
        makeg(grid2,grid,t);
        
        return hehe(grid,t) || hehe(grid,t) || hehe(grid2,t) || hehe(grid2,t);


    }
};