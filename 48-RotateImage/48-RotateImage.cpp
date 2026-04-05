// Last updated: 4/5/2026, 11:48:40 AM
class Solution {
public:

    void transpose(vector<vector<int>>&matrix){
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i>j) swap(matrix[i][j],matrix[j][i]);
            }
        }
    }

    void flip(vector<vector<int>>&matrix){
        int length=matrix[0].size();
        int start=0,end=matrix.size()-1;
        for(start,end;start<length/2;start++,end--){
            for(int row=0;row<matrix.size();row++){
                swap(matrix[row][start],matrix[row][end]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        flip(matrix);
    }
};