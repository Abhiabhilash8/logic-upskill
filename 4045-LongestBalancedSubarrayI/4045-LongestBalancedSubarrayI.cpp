// Last updated: 4/5/2026, 11:42:04 AM
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            map<int,int>odds,evens;
            for(int j=i;j<nums.size();j++){
                if(nums[j]&1) odds[nums[j]]++;
                else evens[nums[j]]++;

                if(odds.size()==evens.size()) ans=max(ans,j-i+1);
            }
        }

        return ans;
    }
};