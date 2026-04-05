// Last updated: 4/5/2026, 11:43:53 AM
class Solution {
public:
    bool check(vector<int>& nums) {
        int c=0;
        int n=nums.size();
        if(n==0||n==1) return true;
        
        if(nums[n-1]>nums[0]) c++;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) c++;
        }
        if(c<=1) return true;
        else return false;
        
    }
};