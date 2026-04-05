// Last updated: 4/5/2026, 11:48:10 AM
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
     int size=1<<nums.size();
     vector<vector<int>>ans;
     for(int i=0;i<size;i++){
        vector<int>temp;
        for(int j=0;j<nums.size();j++){
            if((1<<j) & i){
                temp.push_back(nums[j]);
            }
        }
        ans.push_back(temp);
     }
        return ans;
    }
};