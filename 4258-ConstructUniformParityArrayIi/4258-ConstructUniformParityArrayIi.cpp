// Last updated: 4/5/2026, 11:40:40 AM
class Solution {
public:
    bool f(vector<int>&nums, int r,vector<int>&om){
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(r){
                if((nums[i] & 1) || (nums[i]>om[i])) continue;
                else return false;
            }else{
                if(!(nums[i]&1) || nums[i]>om[i]) continue;
                else return false;
            }
        }

        return true;
    }
    
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        vector<int>om(n,INT_MAX);
        int ovm=INT_MAX;
        for(int i=0;i<n;i++){
            om[i]=ovm;
            if(nums1[i]&1) ovm=min(ovm,nums1[i]);
        }
        ovm=INT_MAX;
        for(int i=n-1;i>=0;i--){
            om[i]=min(ovm,om[i]);
            if(nums1[i]&1) ovm=min(ovm,nums1[i]);
        }
        
        return  f(nums1,0,om) || f(nums1,1,om);
    }
};