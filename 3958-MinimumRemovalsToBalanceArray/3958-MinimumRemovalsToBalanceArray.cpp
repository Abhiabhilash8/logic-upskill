// Last updated: 4/5/2026, 11:42:23 AM
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        for(int i=n-1;i>=0;i--){
            int ind=lower_bound(nums.begin(),nums.begin()+i,ceil((double)nums[i]/k))-nums.begin();
            if(ind>=0 && ind<=i)ans=min(ans,n-i-1+ind);
        }

        return ans;
    }
};