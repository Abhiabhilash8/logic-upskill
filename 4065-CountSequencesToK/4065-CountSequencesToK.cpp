// Last updated: 4/5/2026, 11:41:55 AM
class Solution {
public:
int f(int i,double k,vector<int>&nums,map<pair<int,double>,int>&mpp){
    if(i<0) return abs(k - 1.0) < 1e-9;
    if(k==0) return 0;
    else if(mpp.find({i,k})!=mpp.end()) return mpp[{i,k}];

    return mpp[{i,k}]=f(i-1,k,nums,mpp)+f(i-1,k/(double)nums[i],nums,mpp)+f(i-1,k*nums[i],nums,mpp);
}
    int countSequences(vector<int>& nums, long long k) {
        map<pair<int,double>,int>mpp;
        return f(nums.size()-1,k,nums,mpp);
    }
};