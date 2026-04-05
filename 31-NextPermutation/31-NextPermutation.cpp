// Last updated: 4/5/2026, 11:48:53 AM
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ptr2=nums.size()-2;
       while(ptr2>=0&&nums[ptr2]>=nums[ptr2+1]) ptr2--;

    //    nums[ptr2]<nums[ptr2+1]
        int ptr1=nums.size()-1;
        if(ptr2>=0){
        while(nums[ptr2]>=nums[ptr1]) ptr1--;

        swap(nums[ptr2],nums[ptr1]);

        }

        reverse(nums.begin()+ptr2+1,nums.end());

    }
};