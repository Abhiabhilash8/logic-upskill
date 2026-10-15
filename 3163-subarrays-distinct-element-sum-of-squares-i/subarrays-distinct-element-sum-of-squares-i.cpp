class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int s = 0;
        for(int i = 0; i < nums.size(); i++){
            unordered_set<long long>st;
            for(int j = i; j < nums.size();  j++){
                st.insert(nums[j]);
                s += (st.size() * st.size());
            }
        }

        return s;

    }
};