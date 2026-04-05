// Last updated: 4/5/2026, 11:46:54 AM
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int l=0,r=0,csum=nums[0],count=INT_MAX;
        while(l<nums.size()){
            
            if(csum<target&&r<nums.size()-1){
                csum+=nums[++r];

            }
            else{
                if(target<=csum)
                count=min(count,r-l+1);
                csum-=nums[l++];
            }
        }
        if(count==INT_MAX) return 0;
        return count;
    }
};