// Last updated: 4/5/2026, 11:44:28 AM
class Solution {
public:

    static bool comp(int a, int b){
        int c1=__builtin_popcount(a),c2=__builtin_popcount(b);
        if(c1==c2) return a<b;
        else return c1<c2;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};