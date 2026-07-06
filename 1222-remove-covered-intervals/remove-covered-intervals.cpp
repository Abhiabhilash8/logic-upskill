class Solution {
public:

    /*
           -------   --------
        ------
    */

    int removeCoveredIntervals(vector<vector<int>>& in) {
        sort(in.begin() , in.end());
        int l = -1 , h = -1;
        int n = in.size();
        for(auto &pt: in){
            if(l <= pt[0] && h >= pt[1]){
                n--;
                continue;
            }else if(l == pt[0] && h<= pt[1]){
                n--;
                h = pt[1];
                continue;
            }

            l = pt[0] , h = pt[1];
        }

        return n;
    }
};