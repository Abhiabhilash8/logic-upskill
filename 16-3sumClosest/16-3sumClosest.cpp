// Last updated: 4/5/2026, 11:49:07 AM
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ptr1,ptr2,z,dif,close=INT_MAX;
        sort(nums.begin(),nums.end());
        for(z=0;z<nums.size();z++){
            ptr1=z+1;
            ptr2=nums.size()-1;
            while(ptr1<ptr2){
                dif=target - (nums[z] + nums[ptr1] + nums[ptr2]);
                if(abs(close)>abs(dif))
                 close = dif;
                if(dif==0) return target;
                else if(dif<0) ptr2--;
                else ptr1++;
            }

        }
        return target-close;
    }
};