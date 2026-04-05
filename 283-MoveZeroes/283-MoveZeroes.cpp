// Last updated: 4/5/2026, 11:46:25 AM
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        while(i<n&&nums[i]!=0) i++;
        if(i==n) return;

        j=i+1;
        while(j<n){
            if(nums[j]!=0) swap(nums[i++],nums[j]);

            j++;
            
        }
    }
};