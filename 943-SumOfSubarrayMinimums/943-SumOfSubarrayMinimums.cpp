// Last updated: 4/5/2026, 11:44:59 AM
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>st;
        vector<int>right(arr.size()),left(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(st.size() && arr[st.top()]>=arr[i]) st.pop();

            if(st.size()) right[i]=st.top();
            else right[i]=arr.size();

            st.push(i);
        }
        st=stack<int>();
        for(int i=0;i<arr.size();i++){
            while(st.size() && arr[st.top()]>arr[i]) st.pop();

            if(st.size()) left[i]=st.top();
            else left[i]=-1;

            st.push(i);
        }

        long long ans=0,mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            int l=i-left[i];
            int r=right[i]-i;

            ans=(ans+(l*r)%mod*arr[i])%mod;
        }

        return ans;
    }
};