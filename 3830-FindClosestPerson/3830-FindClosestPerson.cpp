// Last updated: 4/5/2026, 11:42:40 AM
class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(abs(x-z)==abs(y-z)) return 0;
        return (abs(x-z)>abs(y-z))? 2:1;
    }
};