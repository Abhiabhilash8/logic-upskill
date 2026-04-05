// Last updated: 4/5/2026, 11:43:58 AM
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int csum=0,ans=nums[0];;
        set<int>st;
        int ptr1=0,ptr2=0;
        while(ptr2>=ptr1 && ptr2<nums.size()){
            while(st.size() && ptr1<ptr2 && st.find(nums[ptr2])!=st.end()){
                csum-=nums[ptr1];
                st.erase(nums[ptr1++]);
            }
            st.insert(nums[ptr2]);
            csum+=nums[ptr2];
            ans=max(ans,csum);
            ptr2++;
        }

        return ans;
    }
};