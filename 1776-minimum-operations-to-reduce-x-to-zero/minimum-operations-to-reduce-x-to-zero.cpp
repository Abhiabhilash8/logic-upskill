class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        int s = 0;
        mpp[s] = 0;
        for(int i = 0; i < n && s <= x; i++){
            s += nums[i];
            mpp[s] = i + 1;
        }
        int ans = INT_MAX;
        s = 0;
        if(mpp.find(x) != mpp.end()) ans = mpp[x];
        for(int i = n - 1; i >= 0 && s <= x; i--){
            s += nums[i];
            if(mpp.find(x - s) != mpp.end() && mpp[x - s] <= i) ans = min(ans , mpp[x - s] + n - i);
        }

        return ans == INT_MAX? -1: ans;
    }
};