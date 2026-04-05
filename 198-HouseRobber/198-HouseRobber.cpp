// Last updated: 4/5/2026, 11:47:09 AM
class Solution {
public:

    int rob(vector<int>& nums) {


        int prev2=0,prev1=nums[0];
        

        for(int i=2;i<=nums.size();i++){

            int cur=max(prev1,nums[i-1]+prev2);

            prev2=prev1;
            prev1=cur;

        }

        return prev1;
        
    }
};