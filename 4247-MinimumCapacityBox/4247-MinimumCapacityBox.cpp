// Last updated: 4/5/2026, 11:40:55 AM
class Solution {
public:
    int minimumIndex(vector<int>& c, int is) {
        int ind=-1,val=INT_MAX;
        for(int i=0;i<c.size();i++){
            if(ind==-1  && c[i]>=is) ind=i;
            else if(ind !=-1 && c[i]>=is && c[i]<c[ind]) ind = i;
        }
        return ind;
    }
};