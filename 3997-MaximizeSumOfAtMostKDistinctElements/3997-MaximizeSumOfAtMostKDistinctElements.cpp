// Last updated: 4/5/2026, 11:42:17 AM
class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int c=0;
        vector<int>vec;
        for(int i=nums.size()-1;i>=0&&c<k;i--){
            if(i<nums.size()-1&&nums[i]==nums[i+1]){
                continue;
            }
            
            vec.push_back(nums[i]);
            c++;
        }

        return vec;
    }
};