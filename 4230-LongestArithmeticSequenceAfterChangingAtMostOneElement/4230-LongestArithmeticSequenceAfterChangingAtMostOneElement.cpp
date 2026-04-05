// Last updated: 4/5/2026, 11:41:00 AM
class Solution {
public:
    int f(vector<int>&nums){
        int c=2,mc=2,f=0,used=-1,prev=-1;

        for(int i=2;i<nums.size();i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                c++;
                mc=max(c,mc);
            }
            else if(nums[i]-nums[i-1]!=nums[i-1]-nums[i-2] && !f){
                prev=nums[i];
                nums[i]=nums[i-1]+(nums[i-1]-nums[i-2]);
                used=i;
                f=1;
                c++;
                mc=max(mc,c);
            }else{
                nums[used]=prev;
                f=0;
                i=used;
                c=2;
            }
        }

        return mc;

    }
    int longestArithmetic(vector<int>& nums) {
        
        vector<int>n2=nums;
        reverse(n2.begin(),n2.end());
        return max(f(nums),f(n2));
        
        

        

        
    }
};