// Last updated: 4/5/2026, 11:47:32 AM
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') q.push({i,0});
            if(board[i][n-1]=='O') q.push({i,n-1});
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O') q.push({0,i});
            if(board[m-1][i]=='O') q.push({m-1,i});
        }

        while(q.size()){
            int i=q.front().first,j=q.front().second;
            vis[i][j]=1;
            q.pop();
            if(i-1>=0 && !vis[i-1][j] && board[i-1][j]=='O'){
                q.push({i-1,j});
                vis[i-1][j]=1;
            }
            if(j-1>=0 && !vis[i][j-1] && board[i][j-1]=='O'){
                q.push({i,j-1});
                vis[i][j-1]=1;
            }
            if(i+1<m && !vis[i+1][j] && board[i+1][j]=='O'){
                q.push({i+1,j});
                vis[i+1][j]=1;
            }
            if(j+1<n && !vis[i][j+1] && board[i][j+1]=='O'){
                q.push({i,j+1});
                vis[i][j+1]=1;
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]) board[i][j]='X';
            }
        }


    }
};