// Last updated: 4/5/2026, 11:46:51 AM
class Solution {
public:

    int rob(vector<int>& nums) {

        if(nums.size()==1) return nums[0];


        int prev2=0,prev1=nums[0];
        int ans1=0,ans2=0;
        

        for(int i=2;i<nums.size();i++){

            int cur=max(prev1,nums[i-1]+prev2);

            prev2=prev1;
            prev1=cur;

        }
        ans1=prev1;

        prev2=0,prev1=nums[1];

        for(int i=3;i<=nums.size();i++){

            int cur=max(prev1,nums[i-1]+prev2);

            prev2=prev1;
            prev1=cur;

        }
        ans2=prev1;

        return max(ans1,ans2);
        
    }
};