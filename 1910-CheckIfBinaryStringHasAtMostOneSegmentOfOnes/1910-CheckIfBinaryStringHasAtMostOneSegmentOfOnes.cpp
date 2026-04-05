// Last updated: 4/5/2026, 11:43:50 AM
class Solution {
public:
    bool checkOnesSegment(string s) {
        bool z=false;
        for(auto c: s){
            if(z && c=='1') return false;
            else if(c=='0') z=1;
        }

        return true;
    }
};