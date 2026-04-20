class Solution {
public:
    int maxDistance(vector<int>& c) {
        int c1=0,c2=0,a=0;
        for(int i=0;i<c.size();i++){
            if(c[c1] == c[c2]){
                c1 = i;
            }

            if(c[i] != c[c1]) a=max(a,i-c1);
            if(c[i] != c[c2]) a=max(a,i-c2);
        }


        return a;
    }
};