// Last updated: 4/5/2026, 11:42:54 AM
class Solution {
public:
int c(int t){
    for(int i=0;i<=t;i++){
        if(((i)|(i+1))==t) return i;
    }
    return -1;
}
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++) ans[i]=c(nums[i]);
        return ans;
    }
};