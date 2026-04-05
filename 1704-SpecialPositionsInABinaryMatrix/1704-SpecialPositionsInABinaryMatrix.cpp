// Last updated: 4/5/2026, 11:44:10 AM
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int c=0,n=mat.size(),m=mat[0].size();
        vector<int>rt(n,0),ct(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rt[i]+=mat[i][j];
                ct[j]+=mat[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] && rt[i]==1 && ct[j]==1) c++;
            }
        }

        return c;
    }
};