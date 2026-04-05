// Last updated: 4/5/2026, 11:40:59 AM
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size(),f=0;
        vector<long long>ps(n,0),pp(n,0);
        long long s=0;
        for(int i=0;i<n;i++){
            ps[i]=s;
            s+=nums[i];
        }
        long long pro=1;
        for(int i=n-1;i>=0;i--){
            if(f) pp[i]=-1;
            else{
                pp[i]=pro;
                if(pro>=1e15/nums[i]) f=1;
                else pro*=nums[i];
            }
        }



        for(int i=0;i<n;i++){
            if(pp[i]==ps[i]) return i;
        }
        return -1;
    }
};