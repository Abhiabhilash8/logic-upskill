// Last updated: 4/5/2026, 11:42:15 AM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int f=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                f=1;
                break;
            }
        }

        if(f==1) return 1;
        else return 0;
    }
};