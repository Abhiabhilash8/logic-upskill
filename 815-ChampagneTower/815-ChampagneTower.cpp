// Last updated: 4/5/2026, 11:45:09 AM
class Solution {
public:
    double champagneTower(int p, int qr, int qg) {
    vector<double>cur(1,p);
    for(int i=0;i<qr;i++){
        vector<double>next(cur.size()+2,0);
        for(int c=0;c<cur.size();c++){
            if(cur[c]>1){double ex=(cur[c]-1)/2.0;
            next[c]+=ex;
            next[c+1]+=ex;}
        }

        cur=next;
    }        

    return min(1.0,cur[qg]);
        
    }
};