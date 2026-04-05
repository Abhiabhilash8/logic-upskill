// Last updated: 4/5/2026, 11:48:47 AM
class Solution {
public:
void cs(int ind,vector<int>&temp,vector<vector<int>>&ans,vector<int>&candidates,int target,int n){
    if(ind==n){
        if(target==0) ans.push_back(temp);
        return;
    }

    if(candidates[ind]<=target){
    temp.push_back(candidates[ind]);
    cs(ind,temp,ans,candidates,target-candidates[ind],n);
    temp.pop_back();
    }
    cs(ind+1,temp,ans,candidates,target,n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        int n=candidates.size();
        cs(0,temp,ans,candidates,target,n);
        
        return ans;
    }
};