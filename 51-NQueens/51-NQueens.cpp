// Last updated: 4/5/2026, 11:48:37 AM
class Solution {
public:
    void solve(int col,vector<int>&rowcheck,vector<int>&lowerdg,vector<int>&uprdg,vector<vector<string>>&ans,vector<string>&board,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(rowcheck[row]==0&&lowerdg[row+col]==0&&uprdg[n-1+row-col]==0){
                rowcheck[row]=1;
                lowerdg[row+col]=1;
                uprdg[n-1+row-col]=1;
                board[row][col]='Q';
                solve(col+1,rowcheck,lowerdg,uprdg,ans,board,n);
                rowcheck[row]=0;
                lowerdg[row+col]=0;
                uprdg[n-1+row-col]=0;
                board[row][col]='.';
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        vector<int>rowcheck(n,0),lowerdg(2*n-1,0),uprdg(2*n-1,0);

        string s(n,'.');

        for(int i=0;i<n;i++) board[i]=s;

        solve(0,rowcheck,lowerdg,uprdg,ans,board,n);

        return ans;

    }
};