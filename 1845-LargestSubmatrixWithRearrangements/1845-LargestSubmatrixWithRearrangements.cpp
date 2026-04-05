// Last updated: 4/5/2026, 11:43:55 AM
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>con(mat.size(),vector<int>(mat[0].size(),0));
        for(int j=0;j<m;j++){
            int cs=0;
            for(int i=n-1;i>=0;i--){
                if(mat[i][j]==0) cs=0;
                else ++cs;

                con[i][j]=cs;
            }
        }


        int ans=0;
        for(int i=0;i<n;i++){
            sort(con[i].begin(),con[i].end(),greater<int>());
            for(int j=0;j<m && con[i][j];j++){
                ans=max(ans,con[i][j]*(j+1));
            }
        }

        return ans;
    }
};