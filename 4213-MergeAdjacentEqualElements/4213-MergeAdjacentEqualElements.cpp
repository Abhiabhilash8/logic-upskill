// Last updated: 4/5/2026, 11:41:12 AM
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        long long n=nums.size();
        stack<long long>st;
        for(int i=0;i<n;i++){
            long long tp=nums[i];
            while(st.size()>=1 && tp==st.top()){
                st.pop();
                tp=2*tp;
            }
            st.push(tp);
        }
        vector<long long>ans;
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};