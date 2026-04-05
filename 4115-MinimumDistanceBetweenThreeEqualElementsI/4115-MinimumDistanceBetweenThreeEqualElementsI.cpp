// Last updated: 4/5/2026, 11:41:38 AM
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans=INT_MAX;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]!=nums[j]) continue;
                for(int k=j+1;k<nums.size();k++){
                    if(nums[k]!=nums[j]) continue;

                    ans=min(ans,abs(i-j)+abs(k-j)+abs(k-i));
                }
            }
        }


        if(ans==INT_MAX) return -1;
        else return ans;
    }
};