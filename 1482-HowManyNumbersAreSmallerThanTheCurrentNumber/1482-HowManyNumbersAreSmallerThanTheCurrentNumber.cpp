// Last updated: 4/5/2026, 11:44:27 AM
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>temp=nums;
        sort(nums.begin(),nums.end());
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]!=nums[i-1]&&mpp[nums[i]]==0){
                mpp[nums[i]]=i;
            }
            // if(i==2&&nums[i]==nums[i-1]&&nums[i+1]!=nums[i]){
            //     mpp[nums[i]]-=1;
            // }
        }
        vector<int>ans;
        for(int  i=0;i<nums.size();i++){

            ans.push_back(mpp[temp[i]]);
        }
        return ans;
       

    }
};