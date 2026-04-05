// Last updated: 4/5/2026, 11:40:50 AM
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums1[i]]++;
        }

        for(int i=0;i<n;i++){
            if(mpp[nums2[i]]){
                mpp[nums2[i]]--;
                nums2[i]*=-1;
            }
        }
        vector<int>v1,v2;
        int ans=0;
        for(auto it: mpp){
            if(it.second &1) return -1;
            else ans+=it.second/2;
        }
        map<int,int>mpp2;
        for(int i=0;i<n;i++){
            if(nums2[i]>=0) mpp2[nums2[i]]++;
        }

        for(auto it: mpp2){
            if(it.second&1) return -1;
        }

        return ans;

    }
};