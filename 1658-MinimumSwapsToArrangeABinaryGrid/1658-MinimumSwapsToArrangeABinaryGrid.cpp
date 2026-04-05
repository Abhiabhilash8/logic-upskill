// Last updated: 4/5/2026, 11:44:13 AM
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=n-1;j>=0 && grid[i][j]==0;j--,c++);
            v.push_back(c);
        }

        // for(int i=0;i<n;i++) cout<<v[i]<<" ";
        // cout<<endl;


        int req=n-1,ans=0;
        for(int i=0;i<n;i++,req--){
            int j=i;
            for(;j<n;j++){
                if(v[j]>=req) break;
            }
            // cout<<j<<" ";
            if(j==n) return -1;
            for(int k=j;k>i;k--){
                swap(v[k],v[k-1]);
                ans++;
            }
        }

        return ans;
    }
};