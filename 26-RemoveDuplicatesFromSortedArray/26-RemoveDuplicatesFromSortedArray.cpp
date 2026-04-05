// Last updated: 4/5/2026, 11:48:59 AM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;

        int n=nums.size();
        int s=0;

        while(s<n-1&&nums[s]!=nums[s+1]) s++;
        s=s+1;

        int e=s+1;
        while(e<n&&s<n){            
            while(e<n&&nums[e]==nums[s-1]) {
                e++;
            }
            if(e<n){
            swap(nums[s],nums[e]);
            s++;
            }
            e++;
        }
        return s;
        
    }
};