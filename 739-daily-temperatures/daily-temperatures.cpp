class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        stack<int>st;
        vector<int>ans(n , 0) , nm (n , 0);
        for(int i = n-1; i>=0; i--){
            while(st.size() && t[i] >= t[st.top()]){
                st.pop();
            }
            if(st.size()) {nm[i] = st.top();
            ans[i] = nm[i] - i;}
            st.push(i);
        }

        return ans;
    }
};