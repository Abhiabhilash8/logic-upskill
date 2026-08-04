class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int cnt=nums[0];
        for(int i=0;i<nums.size();i++){
            while(cnt!=nums[i]){
                ans.push_back(cnt++);
            }
            cnt++;
        }

        return ans;
        
    }
};