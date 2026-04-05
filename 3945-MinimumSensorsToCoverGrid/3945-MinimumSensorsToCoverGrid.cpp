// Last updated: 4/5/2026, 11:42:26 AM
class Solution {
public:
    int minSensors(int n, int m, int k) {
        return ceil((float)m/(2*k+1))*ceil((float)n/(2*k+1));
    }
};