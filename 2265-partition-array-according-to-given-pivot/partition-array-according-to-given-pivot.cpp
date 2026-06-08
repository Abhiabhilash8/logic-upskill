class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>a;
        int c = 0;

        for(int i = 0; i<nums.size();  i++){
            
            if(nums[i] < pivot) a.push_back(nums[i]);

            c += nums[i] == pivot;
        }

        while(c--) a.push_back(pivot);

        for(int i = 0; i<nums.size(); i++) if(nums[i] > pivot) a.push_back(nums[i]);

        return a;
    }
};