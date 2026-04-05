// Last updated: 4/5/2026, 11:46:47 AM
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>st;
        for(int val:nums){
            st.emplace(val);
        }
        if(st.size()==nums.size())
        return false;
        else
        return true;
        
    }
};