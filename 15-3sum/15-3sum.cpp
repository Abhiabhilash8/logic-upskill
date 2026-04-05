// Last updated: 4/5/2026, 11:49:09 AM
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ptr1=0,ptr2=nums.size()-1;
        set<vector<int>>s;
        vector<int>temp;
        int fix=nums.size()-1;
        for(int z=fix;z>=0;z--){
            ptr1=0,ptr2=nums.size()-1;
                int req=nums[z]*-1;
            while(ptr1!=ptr2){
                if(z==ptr1) ptr1++;
                else if(z==ptr2) ptr2--;
                else if(nums[ptr1]+nums[ptr2]==req){
                    temp.insert(temp.end(),{nums[z],nums[ptr1],nums[ptr2]});
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                    temp.clear();
                    ptr2--;
                }
                else if(nums[ptr1]+nums[ptr2]>req)  ptr2--;
                else if(nums[ptr1]+nums[ptr2]<req)  ptr1++;
            }
        }
        vector<vector<int>>v(s.begin(),s.end());
        return v;
    }
};