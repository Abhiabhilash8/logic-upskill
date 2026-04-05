// Last updated: 4/5/2026, 11:40:48 AM
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[i]==1 && nums[j]==2){
                    ans=min(ans,abs(i-j));
                }
            }
        }


        if(ans==INT_MAX) ans=-1;
        return ans;
    }
};