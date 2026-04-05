// Last updated: 4/5/2026, 11:46:30 AM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,j=matrix[0].size()-1;
        while(j>=0&&i<=matrix.size()-1){
            if(matrix[i][j]==target) return true;
            else if(target>matrix[i][j]) i++;
            else j--;
        }
        return false;
    }
};