// Last updated: 4/5/2026, 11:48:36 AM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0],cursum=0;
        for(int i=0;i<nums.size();i++){
            cursum+=nums[i];
                ans=max(cursum,ans);
            if(cursum<=0){
                cursum=0;
            } 
            
            
        }
        return ans;
    }
};