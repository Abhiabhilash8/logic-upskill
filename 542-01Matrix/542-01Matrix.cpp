// Last updated: 4/5/2026, 11:45:42 AM
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>vis(mat.size(),vector<int>(mat[0].size(),0));
        queue<pair<int,int>>q;
        int c=0,m=mat.size(),n=mat[0].size();
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){ q.push({i,j});vis[i][j]=1;}
                else c++;
            }
        }
        int steps=0;
        int temp=0;
        while(c){
            if(temp==0){
                temp=q.size();
                steps++;
            }
            int i=q.front().first;
            int j=q.front().second;

            q.pop();
            if(i+1<m && !vis[i+1][j]){
                if(mat[i+1][j]==1){
                    mat[i+1][j]=steps;
                    c--;
                }
                    q.push({i+1,j});
                    vis[i+1][j]=1;
            }
            if(i-1>=0 && !vis[i-1][j]){
                if(mat[i-1][j]==1){
                    mat[i-1][j]=steps;
                    c--;
                }
                    q.push({i-1,j});
                    vis[i-1][j]=1;
            }
            if(j+1<n && !vis[i][j+1]){
                if(mat[i][j+1]==1){
                    mat[i][j+1]=steps;
                    c--;
                }
                    q.push({i,j+1});
                    vis[i][j+1]=1;
            }
            if(j-1>=0 && !vis[i][j-1]){
                if(mat[i][j-1]==1){
                    mat[i][j-1]=steps;
                    c--;
                }
                    q.push({i,j-1});
                    vis[i][j-1]=1;
            }

            temp--;

        }


        return mat;


    }
};