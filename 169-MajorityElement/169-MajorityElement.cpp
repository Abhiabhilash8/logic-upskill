// Last updated: 4/5/2026, 11:47:14 AM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int f=0,ans=0;
    
        for(int val:nums){
          if(f==0){
            ans=val;
          }
          if(val==ans){
            f++;
          }
          else
          f--;
        }
        
    return ans;
    }
};