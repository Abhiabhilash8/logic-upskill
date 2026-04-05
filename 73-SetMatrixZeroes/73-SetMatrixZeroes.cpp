// Last updated: 4/5/2026, 11:48:16 AM
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0=1;
        int row=0,col=0;
        for(row=0;row<matrix.size();row++){
            for(col=0;col<matrix[0].size();col++){
                if(matrix[row][col]==0){
                    matrix[row][0]=0;
                    if(col!=0) matrix[0][col]=0;
                    else{
                        col0=0;
                    }
                }
            }
        }


        for(row=1;row<matrix.size();row++){

            for(col=1;col<matrix[0].size();col++){
                if(!matrix[0][col]||!matrix[row][0]) matrix[row][col]=0;
            }
        }
        if(matrix[0][0]==0) for(col=0;col<matrix[0].size();col++) matrix[0][col]=0;
        if(col0==0){
            for(row=0;row<matrix.size();row++) matrix[row][0]=0;
        }

    }
};