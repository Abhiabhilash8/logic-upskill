// Last updated: 4/5/2026, 11:42:06 AM
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans=0;
        int n=nums1.size();
        // int nearest=-1;
        int nearestdiff=INT_MAX;
        bool foundbw=false;
        for(int i=0;i<n;i++){
            ans+=abs(nums1[i]-nums2[i]);
            if((nums2[n]>=nums1[i]&&nums2[n]<=nums2[i])||(nums2[n]<=nums1[i]&&nums2[n]>=nums2[i])) foundbw=true;

            if(nearestdiff>abs(nums2[n]-nums1[i])){
                nearestdiff=abs(nums2[n]-nums1[i]);
            }
            nearestdiff=min({nearestdiff,abs(nums2[n]-nums1[i]),abs(nums2[n]-nums2[i])});
        }

        if(foundbw) return ans+1;
        else return ans+nearestdiff+1;
    }
};