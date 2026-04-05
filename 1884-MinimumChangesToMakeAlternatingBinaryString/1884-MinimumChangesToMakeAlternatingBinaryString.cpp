// Last updated: 4/5/2026, 11:43:51 AM
class Solution {
public:
    int minOperations(string s) {
        char f1='1',f0='0';
        int c1=0,c0=0;
        for(auto c: s){
            if(c!=f1) c1++;
            if(c!=f0) c0++;
            f1=f1=='1'?'0':'1';
            f0=f0=='1'?'0':'1';
        }
        return min(c1,c0);
    }
};