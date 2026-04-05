// Last updated: 4/5/2026, 11:46:41 AM
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int start=0;
        for(int i=0;i<nums.size();i++){
          if(i==0||nums[i]!=nums[i-1]+1){
            start=i;
          }
          if(i==nums.size()-1||nums[i]!=nums[i+1]-1){
            if(start==i){
                ans.push_back(to_string(nums[i]));
            }
            else
            ans.push_back(to_string(nums[start])+"->"+to_string(nums[i]));
          }
        }
        
        return ans;


    }
};