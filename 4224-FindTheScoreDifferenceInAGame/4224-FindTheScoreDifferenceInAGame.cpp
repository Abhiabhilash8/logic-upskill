// Last updated: 4/5/2026, 11:41:05 AM
class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int ans=0,f=0;
        vector<int>v={0,0};
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1){
                f=!f;
            }
            if((i+1)%6==0){
                f=!f;
            }

            v[f]+=nums[i];
        }

        return v[0]-v[1];
    }
};