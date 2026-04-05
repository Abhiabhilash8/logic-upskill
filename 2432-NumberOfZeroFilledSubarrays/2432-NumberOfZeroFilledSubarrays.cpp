// Last updated: 4/5/2026, 11:43:25 AM
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long c=0;
        int st=0,e=0;
        for(;st<nums.size() && e<nums.size();){
            if(nums[st]!=0){
                st++;
                continue;
            }
            else{
                if(st>e)e=st;
                c+=e-st+1;
                e++;
                if(e==nums.size()) break;
                if(nums[e]!=0) st=e;
            }
        }
        return c;
        
    }
};