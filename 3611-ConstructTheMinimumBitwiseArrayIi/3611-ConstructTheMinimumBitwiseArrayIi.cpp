// Last updated: 4/5/2026, 11:42:53 AM
class Solution {
public:
int c(int n){
    int ans=0;
    if(!(n%2)) return -1;
    int i=0;
    while((1<<i)&n) i++;
    ans=n^(1<<(i-1));
    return ans;
}
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i]=c(nums[i]);
        }
        return ans;
    }
};