// Last updated: 4/5/2026, 11:48:04 AM
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        vector<int>rightmin(n),leftmin(n);

        for(int i=n-1;i>=0;i--){
            while(st.size() && heights[i]<=heights[st.top()]) st.pop();
            if(st.size()) rightmin[i]=st.top()-1;
            else rightmin[i]=n-1;
            st.push(i);

        }

        st=stack<int>();
        for(int i=0;i<n;i++){
            while(st.size() && heights[i]<=heights[st.top()]) st.pop();


            if(st.size()) leftmin[i]=st.top()+1;
            else leftmin[i]=0;
            st.push(i);
        }


        int maxans=0;
        for(int i=0;i<n;i++) maxans=max(maxans,heights[i]*(1-leftmin[i]+rightmin[i]));


        return maxans;
    }
};