// Last updated: 4/5/2026, 11:49:22 AM
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<int>nums=arr;

        sort(nums.begin(),nums.end());
        vector<int>ans;
        int ptr1=0,ptr2=nums.size()-1;
        while(ptr1<ptr2){
            if(nums[ptr1]+nums[ptr2]==target){
                int x=find(arr.begin(),arr.end(),nums[ptr1])-arr.begin();
                ans.push_back(x);
                arr[x]=INT_MIN;
                ans.push_back(find(arr.begin(),arr.end(),nums[ptr2])-arr.begin());
                return ans;
            }
            else if(target<nums[ptr1]+nums[ptr2]) ptr2--;

            else  ptr1++;
        }
       return ans;
    }
};