// Last updated: 4/5/2026, 11:48:14 AM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int t=0,b=matrix.size()-1,mc=0;
        while(t<=b){
            mc=(t+b)>>1;
            if(matrix[mc][0]>target) b=mc-1;

            else t=mc+1;
        }
        if(!(b>=0&&b<matrix.size())) return false;


        int mr;
        int l=0,r=matrix[l].size()-1;
        
        while(l<=r){
            mr=(l+r)>>1;
            if(matrix[b][mr]>target) r=mr-1;
            else l=mr+1;
        }

        if(!(r>=0&&r<matrix[0].size())) return false;

        if(matrix[b][r]==target) return true;
        else return false;

    }
};