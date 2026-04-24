class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int u=0,l=0,r=0;
        for(auto c: moves){
            if(c == 'L') l++;
            else if(c == 'R') r++;
            else u++;
        }
        return max( l , r ) - min( l , r) + u;
    }
};