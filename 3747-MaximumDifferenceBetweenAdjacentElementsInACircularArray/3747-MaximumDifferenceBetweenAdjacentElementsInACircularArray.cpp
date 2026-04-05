// Last updated: 4/5/2026, 11:42:49 AM
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int md=nums[nums.size()-1]-nums[0],d=0;
        if(md<0)
        md=-md;
        for(int i=1;i<nums.size();i++){
            d=nums[i]-nums[i-1];
            if(d<0)
            d=-d;
            md=max(md,d);
        }
        return md;
    }
};