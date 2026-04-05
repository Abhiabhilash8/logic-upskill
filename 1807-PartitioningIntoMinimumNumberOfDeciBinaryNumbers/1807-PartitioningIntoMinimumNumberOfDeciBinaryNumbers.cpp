// Last updated: 4/5/2026, 11:43:59 AM
class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(),n.end())-'0';
    }
};