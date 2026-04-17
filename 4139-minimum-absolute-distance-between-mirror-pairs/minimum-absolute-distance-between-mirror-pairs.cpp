class Solution {
public:
    long long nice(int n){
        long long ans=0;
        while(n>0){
            ans=ans*10+n%10;
            n/=10;
        }
        return ans;
    }

    int lol(vector<int>&nums){
        map<long long , int>mpp;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            long long nc = nice(nums[i]);
            if(mpp.find(nums[i])!=mpp.end()){
                ans = min(ans, i - mpp[nums[i]]);
            }

            mpp[nc] = i;
        }

        if(ans == INT_MAX) ans = -1;

        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        return lol(nums);
    }
};