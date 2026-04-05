// Last updated: 4/5/2026, 11:42:50 AM
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        for(int val:nums){
            sum+=val;
        }
        if(sum%2==1)
        return 0;
        else
        return (nums.size()-1);
        
    }
};