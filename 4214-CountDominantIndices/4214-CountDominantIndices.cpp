// Last updated: 4/5/2026, 11:41:10 AM
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int s=nums[nums.size()-1],ans=0;
        for(int i=nums.size()-2;i>=0;i--){
            if((s/(double)(nums.size()-i-1))<nums[i]) ans++;
            s+=nums[i];
        }

        return ans;
    }
};