class Solution {
public:
    int minMoves(vector<int>& nums, int lt) {
        int n = nums.size();
        vector<int>dif(2e5+5,0);
        for(int i = 0; i<n/2; i++){
            dif[2]+=2,dif[2*lt + 1] -= 2;
            dif[min(nums[i] , nums[n-i-1]) + 1]--;
            dif[max(nums[i] , nums[n-i-1]) + lt + 1]++;
            dif[nums[i] + nums[n-i-1]]--;
            dif[nums[i] + nums[n-i-1] + 1]++;
        }

        for(int i = 1; i<dif.size();i++){
            dif[i] += dif[i-1];
        }

        int ans = INT_MAX;
        for(int i = 2; i<dif.size() && i<=2*lt; i++){
            cout<<dif[i]<<" ";
            ans = min(ans , dif[i]);
        }
        return ans;
    }
};