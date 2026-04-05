// Last updated: 4/5/2026, 11:45:49 AM
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans(nums.size(),-1);
        int maxind=max_element(nums.begin(),nums.end())-nums.begin();
        stack<int>st;
        int i=maxind;
        do{
            while(st.size() && st.top()<=nums[i]) st.pop();

            if(st.size()) ans[i]=st.top();
            else ans[i]=-1;

            st.push(nums[i]);

            if(i==0) i=nums.size()-1;
            else i--;

        }while(i!=maxind);

        return ans;

    }
};