// Last updated: 4/5/2026, 11:46:31 AM
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<k;i++){
            while(dq.size() && nums[i]>=nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        for(int i=k;i<nums.size();i++){
            ans.push_back(nums[dq.front()]);
            while(dq.size() && dq.front()<i-k+1) dq.pop_front();
            while(dq.size() && nums[i]>=nums[dq.back()]) dq.pop_back();

            dq.push_back(i);
            cout<<i<<" ";
        }

        ans.push_back(nums[dq.front()]);

        return ans;

    }
};