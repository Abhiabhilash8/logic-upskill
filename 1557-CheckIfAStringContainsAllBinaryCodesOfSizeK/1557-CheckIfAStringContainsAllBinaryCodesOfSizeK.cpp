// Last updated: 4/5/2026, 11:44:22 AM
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>=s.size()) return false;
        set<string>st;
        for(int i=0;i<=s.size()-k;i++){
            st.insert(s.substr(i,k));
        }

        return st.size()==(1<<k);

    }
};