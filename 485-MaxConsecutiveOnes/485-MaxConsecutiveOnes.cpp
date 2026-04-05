// Last updated: 4/5/2026, 11:45:53 AM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0,fans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                ans++;
                fans=max(ans,fans);
            }
            else{
                ans=0;
            }
        }
        // if(ans>=fans) fans=ans;
            return fans;
    }
};