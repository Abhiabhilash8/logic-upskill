// Last updated: 4/5/2026, 11:45:50 AM
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>vec;
        map<int,int>mpp;
        int ptr=nums1.size()-1;
        for(int i=nums2.size()-1;i>=0;i--){
            while(st.size() && st.top()<nums2[i]) st.pop();
                if(st.size() && st.top()>nums2[i]){
                    mpp[nums2[i]]=st.top();
                }else mpp[nums2[i]]=-1;


            st.push(nums2[i]);
        }

        for(int i=0;i<nums1.size();i++){
            vec.push_back(mpp[nums1[i]]);
        }

        return vec;
    }
};