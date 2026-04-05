// Last updated: 4/5/2026, 11:43:30 AM
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // finding mins sum and max sum and return diff

        int n=nums.size();
        vector<int>leftmin(n),rightmin(n),leftmax(n),rightmax(n);

        // find right min
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(st.size() && nums[i]>=nums[st.top()]) st.pop();
            if(st.size()) rightmin[i]=st.top();
            else rightmin[i]=n;

            st.push(i);
        }
        st=stack<int>();
        for(int i=0;i<n;i++){
            while(st.size() && nums[i]>nums[st.top()]) st.pop();
            if(st.size()) leftmin[i]=st.top();
            else leftmin[i]=-1;

            st.push(i);
        }

        long long mins=0,mod=1e9+7;
        for(int i=0;i<n;i++){
            int l=i-leftmin[i];
            int r=rightmin[i]-i;
            mins+=((l*r)%mod * nums[i]);
        }

        // sum of mins is mins
        // find left min
        st=stack<int>();
        for(int i=n-1;i>=0;i--){
            while(st.size() && nums[i]<=nums[st.top()]) st.pop();
            if(st.size()) rightmax[i]=st.top();
            else rightmax[i]=n;

            st.push(i);
        }
        st=stack<int>();
        for(int i=0;i<n;i++){
            while(st.size() && nums[i]<nums[st.top()]) st.pop();
            if(st.size()) leftmax[i]=st.top();
            else leftmax[i]=-1;

            st.push(i);
        }

        long long maxs=0;
        for(int i=0;i<n;i++){
            int l=i-leftmax[i];
            int r=rightmax[i]-i;
            maxs+=((l*r)%mod * nums[i]);
        }


        cout<<"max min "<<maxs<<" "<<mins<<"\n";


        return mins-maxs;




    }
};