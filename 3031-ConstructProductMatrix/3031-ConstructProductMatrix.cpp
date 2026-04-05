// Last updated: 4/5/2026, 11:43:12 AM
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),k=0,M=12345;
        vector<int>v,pre(m*n,0),post(m*n,0);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) v.push_back(grid[i][j]);
        pre[0]=v[0],post[m*n-1]=v[m*n-1];
        for(int i=1;i<m*n;i++){
            pre[i]=((pre[i-1]%M) * (v[i]%M))%M;
            post[m*n-i-1]=((post[m*n-i]%M) * (v[m*n-i-1]%M))%M;
        }

        vector<vector<int>>ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int a=1;
                if(k==0) a=post[k+1]%M;
                else if(k==m*n-1) a=pre[k-1]%M;
                else a=((pre[k-1]%M) * (post[k+1]%M))%M;

                ans[i][j]=a;
                k++;
            }
        }

        return ans;
    }
};