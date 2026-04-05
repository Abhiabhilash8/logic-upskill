// Last updated: 4/5/2026, 11:44:45 AM
class Solution {
public:
    int bitwiseComplement(int n) {
        if(!n) return 1;
        return n^((1<<(32-__builtin_clz(n)))-1);
    }
};