// Last updated: 4/5/2026, 11:43:21 AM
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int hashnums1[10]={0};
        int hashnums2[10]={0},singleans=10;
        int ans=10,min1=10,min2=10;
        for(int i=0;i<nums1.size();i++){
            hashnums1[nums1[i]]++;
            if(min1>nums1[i]) min1=nums1[i];
        }
        for(int i=0;i<nums2.size();i++){
            hashnums2[nums2[i]]++;
            if(hashnums1[nums2[i]]&&(singleans>nums2[i])) singleans=nums2[i];
            if(min2>nums2[i]) min2=nums2[i];
        }

        if(singleans!=10) return singleans;
        
        int tens=min(min1,min2);
        int ones=max(min1,min2);
        return tens*10+ones;
        


        

        
    }
};