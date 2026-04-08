class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int M=1e9+7;
        for(auto q: queries){
            int l=q[0],r=q[1],k=q[2],v=q[3];
            for(int ind=l;ind<=r;ind+=k){
                nums[ind]=(1ll * (nums[ind]%M) * (v%M))%M;
            }
        }

        int xr=0;
        for(int i=0;i<nums.size();i++) xr^=nums[i];

        return xr; 
    }
};