// Last updated: 4/5/2026, 11:48:00 AM
class Solution {
public:

    void f(int ind,int n,vector<int>&nums,vector<int>temp,vector<vector<int>>&ans){
        if(ind==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        f(ind+1,n,nums,temp,ans);
        temp.pop_back();
        while(ind+1<n&&nums[ind]==nums[ind+1]) ind++;

        f(ind+1,n,nums,temp,ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());

        f(0,n,nums,temp,ans);
        return ans;
        
    }
};