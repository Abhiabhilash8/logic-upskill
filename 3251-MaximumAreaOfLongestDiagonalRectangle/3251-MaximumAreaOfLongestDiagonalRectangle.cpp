// Last updated: 4/5/2026, 11:43:08 AM
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxarea=0,diag=0,maxdiag=0;
        for(int i=0;i<dimensions.size();i++){
            int dlength=dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1];
            int area=dimensions[i][0]*dimensions[i][1];
            if(dlength==maxdiag){
                maxarea=max(area,maxarea);
            }
            else if(dlength>maxdiag){
                maxdiag=dlength;
                maxarea=area;
            }
        }

        return maxarea;
    }
};