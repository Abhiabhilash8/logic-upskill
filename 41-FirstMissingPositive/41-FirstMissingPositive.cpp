// Last updated: 4/5/2026, 11:48:44 AM
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
            vector<int>temp(n+1,1);

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0&&nums[i]<=n) temp[nums[i]]=0;
        }
        for(int i=1;i<=n;i++){

            if(temp[i]==1) return i;
        }
        return n+1;
    }
};