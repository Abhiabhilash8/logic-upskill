// Last updated: 4/5/2026, 11:48:09 AM
class Solution {
public:

    bool f(int i,int j,int k,string &word,vector<vector<char>>&board){
        if(k==word.size()) return true;
        if(i>=board.size()||i<0||j>=board[0].size()||j<0||board[i][j]!=word[k]) return false;

        char temp = board[i][j];
        board[i][j]='#';
        bool a1,a2,a3,a4;
        a1=f(i+1,j,k+1,word,board);
        a2=f(i-1,j,k+1,word,board);
        a3=f(i,j-1,k+1,word,board);
        a4=f(i,j+1,k+1,word,board);
        board[i][j]=temp;

        return a1|a2|a3|a4;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        bool a=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                a|=f(i,j,0,word,board);
            }
        }

        return a;

        
    }
};